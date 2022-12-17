#pragma GCC optimize(4)
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
#define db double
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
const int maxn=1005;
const double eps=1e-8;
inline int sign(double x)
{
	return x<eps?(x>-eps?0:-1):1;
}
struct Point
{
	double a,b,c,d,e;
}a[maxn];
int n;
bool vis[maxn];
inline double operator * (const Point &a,const Point &b)
{
	return a.a*b.a+a.b*b.b+a.c*b.c+a.d*b.d+a.e*b.e;
}
inline Point operator - (const Point &a,const Point &b)
{
	return {a.a-b.a,a.b-b.b,a.c-b.c,a.d-b.d,a.e-b.e};
}
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)
	{
		a[i].a=gi(),a[i].b=gi();
		a[i].c=gi(),a[i].d=gi();
		a[i].e=gi();
	}
}
inline void solve()
{
	FOR(i,1,n)
	{
		bool ok=0;
		FOR(j,1,n)
		{
			if(i==j)continue;
			FOR(k,1,n)
			{
				if(i==k||j==k)continue;
				double val1=(a[i]-a[j])*(a[i]-a[k]);
				double val2=sqrt((a[i]-a[j])*(a[i]-a[j]))+sqrt((a[i]-a[k])*(a[i]-a[k]));
				val1/=val2;
				if(sign(val1)>0)
				{
					ok=1;break;
				}
			}
			if(ok)break;
		}
		if(ok)vis[i]=1;
	}
	int cnt=0;
	FOR(i,1,n)if(!vis[i])cnt++;
	printf("%d\n",cnt);
	FOR(i,1,n)if(!vis[i])printf("%d ",i);
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