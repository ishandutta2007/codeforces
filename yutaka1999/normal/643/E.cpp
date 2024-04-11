#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005
#define LIM 80

using namespace std;
typedef long double ld;

int par[SIZE],dep[SIZE];
ld dp[SIZE][LIM];

int main()
{
	int q;
	scanf("%d",&q);
	par[0]=-1;
	dep[0]=0;
	dp[0][0]=1.0;
	int sz=1;
	for(int i=0;i<q;i++)
	{
		int tp,v;
		scanf("%d %d",&tp,&v);v--;
		if(tp==1)
		{
			par[sz]=v;
			dep[sz]=0;
			dp[sz][0]=1.0;//[m
			int now=sz;
			ld bef=1.0;
			for(int i=1;i<LIM;i++)
			{
				ld nxt=1.0-dp[v][i]/2.0;
				ld back=1.0-dp[v][i];//dp[v][i]=1.0-mul{1.0-dp[ch][i-1]/2.0}
				back/=bef;//bef>=1/2
				back*=1.0-dp[now][i-1]/2.0;
				dp[v][i]=1.0-back;
				bef=nxt;
				now=v;
				v=par[v];
				if(v==-1) break;
			}
			sz++;
		}
		else
		{
			ld ans=0.0;
			for(int i=1;i<LIM;i++) ans+=dp[v][i];
			printf("%.10f\n",(double) ans);
		}/*
		for(int i=0;i<sz;i++)
		{
			for(int j=0;j<=5;j++) printf("%f ",(double) dp[i][j]);puts("");
		}*/
	}
	return 0;
}