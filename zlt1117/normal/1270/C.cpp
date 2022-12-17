//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e5+5;
int a[maxn],n;
ll sum,xsum;
inline void init()
{
	sum=0,xsum=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),sum+=a[i],xsum^=a[i];
}
inline void solve()
{
	printf("%d\n",3);
	ll now=0;
	if(sum%2==1)now=(1LL<<50)+1,sum+=(1LL<<50)+1,xsum^=(1LL<<50)+1;
	else now=(1LL<<50),sum+=(1LL<<50),xsum^=(1LL<<50);
	ll delta=xsum*2-sum;
	printf("%lld %lld %lld\n",now,delta/2,delta/2);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();	
	}
	return 0;
}