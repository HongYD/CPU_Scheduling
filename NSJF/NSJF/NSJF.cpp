#include<stdio.h>
typedef struct nonpresjf
{
	int at, bt, ft, tat, wt;
}nonpresjf;
nonpresjf p[20], p1[20];
int main()
{
	int i, limit, nextval, m, min, n;
	//limit:所有process的运行时间之和
	//nextval:下一个被送进CPU执行的process编号
	//m:用来存放最小Burst Time的process的编号
	//n:process数量
	//min：最小burst time
	p[0].wt = p[0].tat;
	printf("\nEnter the number of process: ");
	scanf("%d",&n);
	printf("\n");
	for (i = 1; i <= n; i++)
	{
		printf("\nEnter the arrival time for the process P%d: ",i);
		scanf("%d",&p[i].at);
	}
	limit = p[1].at;
	for (i = 1; i <= n; i++)
	{
		printf("\nEnter the burst time for the process P%d: ", i);
		scanf("%d", &p[i].bt);
	}
	for (i = 1; i <= n; i++)
	{
		limit += p[i].bt;
	}
	for (i = 1; i <= n; i++)
	{
		p1[i] = p[i];
	}

	printf("\n\nGantt chart is as follows: ");
	printf("%d",p[1].at);
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
			printf("->P%d->%d",m,nextval);
			if (p[m].bt == 0)
			{
				p[m].ft = nextval;
				p[m].tat = p[m].ft - p[m].at;
				p[m].wt = p[m].tat - p1[m].bt;
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
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p1[i].bt,p[i].ft,p[i].tat,p[i].wt);
	}
	printf("\n\n-------------------------------------------------------\n");
	return 0;
}