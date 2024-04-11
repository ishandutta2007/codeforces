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
const int maxn=1e5+5;
int T,n,a[maxn];
int main()
{
	T=gi();
	while(T--)
	{
		n=gi();
		memset(a,0,sizeof(a));
		FOR(i,1,n)
		{
			int x=gi();
			int now=0;
			while(x)
			{
				now++;
				x>>=1;
			}
			a[now]++;
		}
		ll ans=0;
		FOR(i,0,60)ans+=1LL*a[i]*(a[i]-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}