#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstdio>
using namespace std;

typedef struct process
{
	int id, at, bt, st, ft, pr;
	float wt, tat;
}process;

process p[10], p1[10], temp;
queue<int>q1;

int accept(int ch);
void turnwait(int n);
void display(int n);
void ganttrr(int n);

int main()
{
	int i, n, ts, ch, j, x;
	p[0].tat = 0;
	p[0].wt = 0;
	n = accept(ch);
	ganttrr(n);
	turnwait(n);
	display(n);
	return 0;
}

int accept(int ch)
{
	int i, n;
	printf("\nEnter the number of process: ");
	scanf("%d", &n);
	if (n == 0)
	{
		printf("\nInvalid number of process");
		exit(1);
	}
	for (i = 1; i <= n; i++)
	{
		printf("\nEnter the arrival time for process P%d: ",i);
		scanf("%d",&p[i].at);
		p[i].id = i;
	}
	for (i = 1; i <= n; i++)
	{
		printf("\nEnter the burst time for process P%d",i);
		scanf("%d", &p[i].bt);
	}

	printf("==============================================================");
	printf("\nProcess\tAT\tBT");
	for (i = 1; i <= n; i++)
	{
		printf("\nP%d\t%d\t%d",p[i].id,p[i].at,p[i].bt);
	}
	printf("==============================================================");

	for (i = 1; i <= n; i++)
	{
		p1[i] = p[i];
		return n;
	}
}
void ganttrr(int n)
{
	int i, ts, m, nextval, nextarr;

}