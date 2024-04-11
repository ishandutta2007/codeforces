
#include<stdio.h>
#include<stdlib.h>
int sum[1000005];
int main(void)
{
	int T, n, m, i, j, x, y, p, now, temp;
	scanf("%d", &T);
	now = 0;
	for(i=1;i<=T;i++)
	{
		scanf("%d", &x);
		sum[x]++;
		if(sum[x]==1)
			now++;
	}
	if(sum[0]!=1)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=2005;i++)
	{
		if(sum[i]>4*i)
		{
			printf("-1\n");
			return 0;
		}
		if(sum[i]<4*i)
			break;
	}
	p = i;
	for(n=1;n*n<=T;n++)
	{
		m = T/n;
		if(T%n || n<p*2-1 || m<p*2-1)
			continue;
		x = y = p;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				temp = abs(i-x)+abs(j-y);
				sum[temp]--;
				if(sum[temp]==0)
					now--;
				if(sum[temp]==-1)
					now++;
			}
		}
		if(now==0)
		{
			printf("%d %d\n%d %d\n", n, m, x, y);
			return 0;
		}
		for(y++;y+p-1<=m;y++)
		{
			for(i=1;i<=n;i++)
			{
				temp = abs(i-x)+abs(1-y);
				sum[temp]--;
				if(sum[temp]==0)
					now--;
				if(sum[temp]==-1)
					now++;
				temp = abs(i-x)+abs(m+1-y);
				sum[temp]++;
				if(sum[temp]==0)
					now--;
				if(sum[temp]==1)
					now++;
			}
			if(now==0)
			{
				printf("%d %d\n%d %d\n", n, m, x, y);
				return 0;
			}
		}
		for(y--,x++;x+p-1<=n;x++)
		{
			for(i=1;i<=m;i++)
			{
				temp = abs(1-x)+abs(i-y);
				sum[temp]--;
				if(sum[temp]==0)
					now--;
				if(sum[temp]==-1)
					now++;
				temp = abs(n+1-x)+abs(i-y);
				sum[temp]++;
				if(sum[temp]==0)
					now--;
				if(sum[temp]==1)
					now++;
			}
			if(now==0)
			{
				printf("%d %d\n%d %d\n", n, m, x, y);
				return 0;
			}
		}
		x--;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				temp = abs(i-x)+abs(j-y);
				sum[temp]++;
				if(sum[temp]==0)
					now--;
				if(sum[temp]==1)
					now++;
			}
		}
	}
	printf("-1\n");
	return 0;
}