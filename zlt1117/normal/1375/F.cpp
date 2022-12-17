//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline ll query(ll x)
{
	printf("%lld\n",x);
	fflush(stdout);
	scanf("%lld",&x);
	return x;
}
ll a[3],id[3];
inline void init()
{

}
inline void input()
{
	scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
	id[0]=a[0],id[1]=a[1],id[2]=a[2];
	sort(a,a+3);
	printf("First\n");
	fflush(stdout);
}
inline void solve()
{
	int x=query(2*a[2]-a[0]-a[1])-1,tmp=x;
	FOR(i,0,2)if(id[x]==a[i]){x=i;break;}
	if(x==0)
	{
		query(a[2]-a[1]);
		return ;
	}
	if(x==1)
	{
		query(a[2]-a[0]);
		return ;
	}
	id[tmp]+=2*a[2]-a[0]-a[1];
	a[2]+=2*a[2]-a[0]-a[1];
	x=query(2*a[2]-a[0]-a[1])-1;
	FOR(i,0,2)if(id[x]==a[i]){x=i;break;}
	if(x==0)
	{
		query(a[2]-a[1]);
		return ;
	}
	if(x==1)
	{
		query(a[2]-a[0]);
		return ;
	}
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}