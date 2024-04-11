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
const int maxn=1e5+5;
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int T,n,a[maxn];
int main()
{
	T=getint();
	while(T--)
	{
		ll ans=-1e18;
		n=getint();
		FOR(i,1,n)a[i]=getint();
		sort(a+1,a+n+1);
		ll sum1=1,sum2=a[1]*a[2],sum3=a[1]*a[2];
		sum3=sum3*a[3]*a[4];
		sum1=sum1*a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4];
		sum2=sum2*a[n]*a[n-1]*a[n-2];
		sum3=sum3*a[n];
		ans=max(ans,max(sum1,max(sum2,sum3)));
		FOR(i,1,n-4)
		{
			ll temp=1;
			FOR(j,i,i+4)temp*=a[j];
			ans=max(ans,temp);
		}
		printf("%lld\n",ans);
	}
	return 0;
}