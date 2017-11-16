#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstdio>
using namespace std;

typedef struct process
{
	int id, at, bt, st, ft, pr;
	//id:the id of the process
	//at:the arrival time of the process
	//bt:burst time of the process
	//st:start time of the process
	//ft:finish time of the process
	//pr:the priority of the process
	float wt, tat;
}process;

process p[10], p1[10], temp;
queue<int>q1;

int accept_inputs(int ch);
void shortest_job_sort(int n);
void gantt_nsjf(int n);
void gantt_psjf(int n);
void gantt_priority_sch(int n);
void gantt_rr(int n);
void gantt_fcfs(int n);
void turnwait(int n);
void display(int n);

int main()
{
	int i, n, ts, ch, j, x;
	do {
		p[0].tat = 0;
		p[0].wt = 0;
		printf("\n*************MENU******************");
		printf("\n1.Select 1 to FCFS");
		printf("\n2.Select 2 to Non Preemptive SJF");
		printf("\n3.Select 3 to Preemptive SJF");
		printf("\n4.Select 4 to Priority Scheduling");
		printf("\n5.Select 5 to Round Robin");
		printf("\n6.Select 6 to EXIT");

		printf("\n\nEnter your choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			n = accept_inputs(ch);
			gantt_fcfs(n);
			turnwait(n);
			display(n);
			break;

		case 2:
			n = accept_inputs(ch);
			shortest_job_sort(n);
			gantt_nsjf(n);
			turnwait(n);
			display(n);
			break;

		case 3:
			n = accept_inputs(ch);
			shortest_job_sort(n);
			gantt_psjf(n);
			turnwait(n);
			display(n);
			break;

		case 4:
			n = accept_inputs(ch);
			gantt_priority_sch(n);
			turnwait(n);
			display(n);
			break;
		case 5:
			n = accept_inputs(ch);
			gantt_rr(n);
			turnwait(n);
			display(n);
			break;
		case 6:
			return 0;
		default:
			cout << "You Entered a wrong value: ";
			break;
		}

	} while (ch != 6);
	return 0;
}

int accept(int ch)
{
	int i, n;
	
	printf("\nEnter the number of process: ");
	scanf("%d",&n);
	if (n == 0)
	{
		printf("\nInvalid number of the process");
		exit(1);
	}
	for (int i = 1; i <= n; i++)
	{
		p[i].pr = NULL;
	}
	for (i = 1; i <= n; i++)
	{
		printf("\Enter the arrival time for process P%d: ", i);
		scanf("%d",&p[i].at);
		p[i].id = i;
	}
	for (i = 1; i <= n; i++)
	{
		printf("\nEnter the burst time for process P%d: ", i);
		scanf("%d",&p[i].bt);
	}
	if (ch == 4)
	{
		for (i = 1; i <= n; i++)
		{
			printf("\nEnter the priority for P%d: ",i);
			scanf("%d", &p[i].pr);
		}
		return n;
	}
	printf("\nInputs given by the user are:\n");
	printf("==============================================================");
	printf("\nprocess\tAT\tBT\tPR");
	for (i = 1; i <= n; i++)
	{
		if (p[i].pr != NULL)
		{
			printf("\nP%d\t%d\t%d\t%d", p[i].id, p[i].at, p[i].bt,p[i].pr);
		}
		else
		{
			printf("\nP%d\t%d\t%d", p[i].id, p[i].at, p[i].bt);
		}
	}
	printf("==============================================================");
	for (i = 1; i <= n; i++)
	{
		p1[i] = p[i];
	}
	return n;
}


void gantt_fcfs(int n)
{
	int i;
	p[1].st = p[1].at;
	for (i = 2; i <= n; i++)
	{
		p[i].st = p[i - 1].st + p[i - 1].bt;
	}
	p[1].ft = p[1].bt;
	for (i = 2; i <= n; i++)
	{
		p[i].ft = p[i - 1].ft + p[i].bt;
	}
	printf("\nGantt Chart is as follows:\n\n");
	printf("%d->P%d->%d",p[1].st,p[1].id,p[1].ft);
	for (i = 2; i <= n; i++)
	{
		printf("->P%d->%d",p[i].id,p[i].ft);
	}
	printf("\n");
}

void shortest_job_sort(int n)
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (p[j].at > p[i].at)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
			else if (p[j].at == p[i].at)
			{
				if (p[j].bt > p[i].bt)
				{
					temp = p[i];
					p[i] = p[j];
					p[j] = temp;
				}
			}
		}
	}
}

void gantt_nsjf(int n)
{
	int i, limit, nextval, m, min;

	p[0].wt = p[0].tat;
	limit = p[1].at;

	for (i = 1; i <= n; i++)
	{
		limit += p[i].bt;
	}
	for (i = 1; i <= n; i++)
	{
		p1[n] = p[i];
	}
	printf("\n\nGantt Chart is as follow: ");
	printf("%d", p[1].at);
	nextval = p[1].at;
	m = 1;
	do
	{
		min = 9999;
		for (i = 1; p[i].at <= nextval&&i <= n; i++)
		{
			if (p[i].bt < min&&p[i].bt>0)
			{
				m = i;
				min = p[i].bt;
			}
			nextval += p[m].bt;
			p[m].bt = 0;
			printf("->P%d",m,nextval);
			if (p[m].bt == 0)
			{
				p[m].ft = nextval;
				p[m].tat = p[m].ft - p[m].at;
				p[m].wt = p[m].tat = p1[m].bt;
				p[0].tat += p[m].tat;
				p[0].wt += p[m].wt;
			}
		}
	} while (nextval < limit);
	p[0].tat = p[0].tat / n;
	p[0].wt = p[0].wt / n;

	printf("\n\n-------------------------TABLE-------------------------\n");

	printf("\nProcess\tAT\tBT\tFT\tTAT\tWT\n");
	for (i = 1; i <= n; i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\n", i, p[i].at, p1[i].bt, p[i].ft, p[i].tat, p[i].wt);
	}
	printf("\n\n-------------------------------------------------------\n");
}


