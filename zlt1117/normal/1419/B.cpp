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
int T;
ll x,pre[35];
int main()
{
	T=gi();
	ll sum=2;
	FOR(i,1,30)
	{
		pre[i]=(sum)*(sum-1)/2;
		sum*=2;
	}
	while(T--)
	{
		scanf("%lld",&x);
		sum=0;
		bool ok=false;
		FOR(i,1,30)
		{
			sum+=pre[i];
			if(sum>x)
			{
				printf("%d\n",i-1);
				ok=true;
				break;
			}
		}
		if(!ok)printf("30\n");
	}
	return 0;
}