
#include<stdio.h>
typedef struct presjf
{
	int at, bt, ft, tat, wt;
}presjf;
presjf p[20], p1[20];
int main()
{
	int i, limit, nextval, m, min, n,tempid;
	p[0].wt = p[0].tat = 0;
	printf("\nEnter the no of process: ");
	scanf("%d", &n);
	printf("\n\n");
	for (i = 1; i <= n; i++)
	{
		printf("Enter the arrival time for the process P%d: ", i);
		scanf("%d", &p[i].at);
	}
	limit = p[1].at;
	for (i = 1; i <= n; i++)
	{
		printf("Enter the burst time for the process P%d: ", i);
		scanf("%d", &p[i].bt);
	}
	for (i = 1; i <= n; i++)
		limit += p[i].bt;
	for (i = 1; i <= n; i++)
		p1[i] = p[i];
	printf("\n\nGantt chart is as follows: \n\n");
	printf("%d", p[1].at);
	nextval = p[1].at;
	m = 1;
	tempid = 1;
	do
	{
		min = 9999;
		for (i = 1; p[i].at <= nextval && i <= n; i++) {
			//p[i].at<=nextval用来检测当前process是否已经到达ready queue!
			if (p[i].bt < min && p[i].bt>0)
			{
				m = i;
				min = p[i].bt;
			}
		}
		nextval += 1;
		p[m].bt = p[m].bt - 1;
		if (tempid != m) {
			printf("->P%d->%d", tempid, nextval-1);
		}
		tempid = m;
		/*for (i = 1; i <= n; i++)
		{
			if (p[i].bt == 0 && i == n)
			{
				printf("->P%d->%d", m, nextval - 1);
			}
		}*/
		if (p[m].bt == 0)
		{
			p[m].ft = nextval;
			p[m].tat = p[m].ft - p[m].at;
			p[m].wt = p[m].tat - p1[m].bt;
			p[0].tat += p[m].tat;
			p[0].wt += p[m].wt;
		}
	} while (nextval<limit);
	for (i = 1; i <= n; i++)
	{
		if (p[i].bt == 0 && i == n)
		{
			printf("->P%d->%d", m, nextval);
		}
	}
	p[0].tat = p[0].tat / n;
	p[0].wt = p[0].wt / n;
	printf("\n\n-------------------TABLE----------------------------------\n");
	printf("\nProcess\tAT\tBT\tFT\tTAT\tWT\n");
	for (i = 1; i <= n; i++)
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\n", i, p[i].at, p1[i].bt, p[i].ft, p[i].tat, p[i].wt);
	printf("\n\n-----------------------------------------------------------\n");
	return 0;
}