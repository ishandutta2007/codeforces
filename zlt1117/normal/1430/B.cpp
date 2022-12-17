#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rd (rand()<<16^rand())
#define pb push_back
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
const int maxn=2e5+5;
int T,n,k,a[maxn];
ll ans;
int main()
{
	T=gi();
	while(T--)
	{
		ans=0;
		n=gi(),k=gi();
		FOR(i,1,n)a[i]=gi();
		sort(a+1,a+n+1);
		sort(a+1,a+n+1,greater<int>());
		FOR(i,1,k+1)ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}