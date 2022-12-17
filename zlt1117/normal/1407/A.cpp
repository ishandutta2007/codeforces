#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#include<bitset>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1005;
bitset<2005>dp[maxn][maxn];///ij 
int T,n,a[maxn];
int main()
{
	T=getint();
	while(T--)
	{
		n=getint();
		dp[0][0][n]=1;
		FOR(i,1,n)
		{
			a[i]=getint();
			FOR(j,0,i)
			{
				dp[i][j]|=dp[i-1][j];
				if(j%2==0)dp[i][j+1]|=dp[i-1][j]<<a[i];
				else dp[i][j+1]|=dp[i-1][j]>>a[i];
			}
		}
		for(int i=n;i>=n/2;--i)
		{
			if(dp[n][i][n])
			{
				printf("%d\n",i);
				vector<int>v;
				int cho=i,now=n;
				for(int j=n;j>=1;--j)
				{
					if(cho>=1&&dp[j-1][cho-1][now]&&a[j]==0)v.push_back(0),cho--;
					else if(a[j]==1&&cho>=1)
					{
						if(cho%2==0)
						{
							if(dp[j-1][cho-1][now+1])cho--,now++,v.push_back(1);
						}
						else
						{
							if(dp[j-1][cho-1][now-1])cho--,now--,v.push_back(1);
						}
					}
				}
				reverse(v.begin(),v.end());
				FOR(j,0,(int)(v.size())-1)printf("%d ",v[j]);
				printf("\n");
				break;
			}
		}
		FOR(i,0,n)FOR(j,0,i)dp[i][j]=0;
	}
	return 0;
}///