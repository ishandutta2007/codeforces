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
const int maxn=1e5+5;
int a[maxn],T,n;
int main()
{
	T=getint();
	while(T--)
	{
		ll ans=0;
		n=getint();
		FOR(i,1,n)a[i]=getint();
		int la=1,lb=1;
		while(a[la]<=0)la++;
		while(a[lb]>=0)lb++;
		while(la<=n&&lb<=n)
		{
			if(la>=lb)
			{
				ans-=a[lb];
				lb++;
				while(a[la]<=0)la++;
				while(a[lb]>=0)lb++;
				continue;
			}
			if(a[la]+a[lb]>=0)
			{
				if(la>=lb)ans+=-a[lb];
				a[la]+=a[lb],a[lb]=0;
			}
			else
			{
				if(la>=lb)ans+=a[la];
				a[lb]+=a[la],a[la]=0;
			}
			while(a[la]<=0)la++;
			while(a[lb]>=0)lb++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}