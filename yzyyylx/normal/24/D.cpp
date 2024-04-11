#include<iostream>
#include<cstdio>
#include<cmath>
#define db double
#define eps 1e-8
#define N 1010
using namespace std;

int m,n,x,y;
db num[N][N],last[N];

void clear()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		num[i][n+1]=0;
		for(j=i-1;j<=i+1;j++)
		{
			num[i][j]=0;
		}
	}
}

inline void xy()
{
	int i,j,k;
	db t;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(fabs(num[j][i])<eps) break;
			t=num[j][i]/num[i][i];
			for(k=i;k<=n;k++)
			{
				if(fabs(num[i][k])<eps) break;
				num[j][k]-=t*num[i][k];
			}
			num[j][n+1]-=t*num[i][n+1];
		}
	}
}

int main()
{
	int i,j,k,t;
	db tmp;
	cin>>m>>n>>x>>y;
	if(m==x)
	{
		puts("0.0000000000");
		return 0;
	}
	for(i=m-1;i>=x;i--)
	{
		clear();
		for(j=1;j<=n;j++)
		{
			t=4-(j==1)-(j==n);
			tmp=1/(db)t;
			if(j>1) num[j][j-1]=tmp;
			if(j<n) num[j][j+1]=tmp;
			num[j][j]=tmp-1;
			num[j][n+1]=tmp*last[j]+1;
		}
		xy();
		for(j=n;j>=1;j--)
		{
			tmp=num[j][n+1];
			for(k=j+1;k<=n;k++)
			{
				if(fabs(num[j][k])<eps) break;
				tmp+=num[j][k]*last[k];
			}
			last[j]=-tmp/num[j][j];
		}
	}
	printf("%.10f",last[y]);
}