#include<stdlib.h>
#include<stdio.h>

typedef struct process
{
	int id, at, bt, st, ft, pr;
	float wt, tat;
	//id:the count number of process;
	//at:arrival time;
	//bt:burst time;
	//st:start time;
	//ft:finish time;
	//wt:wait time;
    //tat:turn around time;
}process;
process p[10], p1[10], temp;
//p[10]:process that input from the user;
//p1[10]:process that copy form the p[10];
//temp:
int accept();//function to accept inputs from the user;
void turnwait(int n);//function to calculating turn around time or wait time.
void display(int n);//function for displaying the calculating result
void ganttfcfs(int n);//function for displaying gantt chart
int main()
{
	int n;
	p[0].tat = 0;
	p[0].wt = 0;
	n = accept();//the number of processes
	ganttfcfs(n);
	turnwait(n);
	display(n);
	return 0;
}
int accept()
{
	int i, n;
	printf("\nEnter the number of the process: ");
	scanf("%d", &n);
	if (n == 0)
	{
		printf("\nInvalid number of process: ");
		exit(1);
	}
	for (i = 1; i <= n; i++)
	{
		printf("\nEnter the arrival time for process P%d: ", i);
		scanf("%d", &p[i].at);
		p[i].id = i;
	}
	for (i = 1; i <= n; i++)
	{
		printf("\nEnter the burst time for process P%d: ", i);
		scanf("%d", &p[i].bt);
	}
	printf("\nInputs given by the user are:\n");
	printf("============================================");
	printf("\nProcess\tAT\tBT");
	for (i = 1; i <= n; i++)
	{
		printf("\nP%d\t%d\t%d",p[i].id,p[i].at,p[i].bt);
	}
	printf("\n============================================");
	for (i = 1; i <= n; i++)
	{
		p1[i] = p[i];
	}
	return n;
}
void ganttfcfs(int n)
{
	//int i, j;
	//p[1].st = p[1].at;
	//for (i = 2; i < n; i++)
	//{
	//	//p[i]的开始时间就是上一个进程的开始时间加上一个进程的运行时间（burst time)
	//	p[i].st = p[i - 1].st + p[i - 1].bt;
	//}
	//p[1].ft =p[1].at+p[1].bt;
	//for (i = 2; i <= n; i++)
	//{
	//	//p[i]的结束时间是上一个进程的结束时间加上上一个进程的运行时间(burst time)
	//	p[i].ft = p[i - 1].ft + p[i].bt;
	//}
	//printf("  ");
	//for (i = 1; i < n; i++)
	//{
	//	for (int j = 0; j < p[i].bt; j++)printf("--");
	//	printf("  ");
	//}
	//printf("\n|");

	//for (i = 1; i < n; i++)
	//{
	//	for (j = 0; j < p[i].bt - 1; j++)printf("  ");
	//	printf("P%d",p[i].id);
	//	for (j = 0; j < p[i].bt - 1; j++)printf("  ");
	//	printf("|");
	//}
	//printf("\n ");

	//for (i = 1; i < n; i++)
	//{
	//	for (j = 0; j < p[i].bt - 1; j++)printf("--");
	//	printf("  ");
	//}
	//printf("\n");


	//printf("0");
	//for (i = 1; i < n; i++)
	//{
	//	for (j = 0; j < p[i].bt; j++)printf("  ");
	//	if (p[i].tat>9)printf("\b");
	//	printf("%d", p[i].ft);
	//}
	//printf("\n");




	int i,j;
	p[1].st = p[1].at;
	for (i = 2; i <= n; i++)
	{
		//p[i]的开始时间就是上一个进程的开始时间加上一个进程的运行时间（burst time)
		p[i].st = p[i - 1].st + p[i - 1].bt;
	}
	p[1].ft =p[1].at+p[1].bt;
	for (i = 2; i <= n; i++)
	{
		//p[i]的结束时间是上一个进程的结束时间加上上一个进程的运行时间(burst time)
		p[i].ft = p[i - 1].ft + p[i].bt;
	}
	printf("\nGantt Chart is as follows:\n\n");
	//print the top bar:
	

	printf(" ");
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= p[i].bt; j++)
		{
			printf("--");
		}
		printf(" ");
	}
	printf("\n|");
	//print the process id at middle:
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= p[i].bt-1; j++)
		{
			printf(" ");
		}
		printf("P%d", p[i].id);
		for (j = 0; j <= p[i].bt-1; j++)
		{
			printf(" ");
		}
		printf("|");
	}
	printf("\n");
	//print the button
	printf(" ");
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= p[i].bt; j++)
		{
			printf("--");
		}
		printf(" ");
	}
	printf("\n");
	printf("0");
	//print the time line
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= p[i].bt; j++)
		{
			printf("  ");
		}
		if (p[i].ft > 9)printf("\b");
		printf("%d", p[i].ft);
	}

	/*printf("%d->P%d->%d",p[1].st,p[1].id,p[1].ft);
	for (i = 2; i <= n; i++)
	{
		printf("");
		printf("|P%d->%d",p[i].id, p[i].ft);
	}
	printf("|");
	printf("\n");*/

}

void turnwait(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		(float)p[i].tat = p[i].ft - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		//p[0]用来存储总和与计算平均
		p[0].tat = p[0].tat + p[i].tat;
		p[0].wt = p[0].wt + p[i].wt;
	}
	p[0].tat = p[0].tat / n;
	p[0].wt = p[0].wt / n;
}

void display(int n)
{
	int i;
	printf("\n\n----------------------------------------Result\tTable----------------------------------------\n");
	printf("\nProcess\tAT\tBT\tFT\tTAT\tWT");
	for (i = 1; i <= n; i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%.2f\t%.2f",p[i].id,p[i].at,p[i].bt,p[i].ft,p[i].tat,p[i].wt);
	}
	printf("\n\n----------------------------------------Result\tTable----------------------------------------");

	printf("\nAverage Turn Around Time:%.2f",p[0].tat);
	printf("\nAverage Waiting Time:%.2f\n",p[0].wt);
}