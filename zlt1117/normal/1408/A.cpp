#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int gi()
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
const int maxn=205;
int T,a[maxn][5],n;
int main()
{
	T=gi();
	while(T--)
	{
		memset(a,0,sizeof(a));
		n=gi();
		FOR(i,1,n)a[i][0]=gi();
		FOR(i,1,n)a[i][1]=gi();
		FOR(i,1,n)a[i][2]=gi();
		printf("%d ",a[1][0]);
		int cho=0;
		FOR(i,2,n-1)
		{
			FOR(j,0,2)
			{
				if(a[i][j]!=a[i-1][cho])
				{
					cho=j;
					printf("%d ",a[i][j]);
					break;
				}
			}
		}
		FOR(j,0,2)
		{
			if(a[n][j]!=a[n-1][cho]&&a[n][j]!=a[1][0])
			{
				printf("%d\n",a[n][j]);
				break;
			}
		}
	}
	return 0;
}