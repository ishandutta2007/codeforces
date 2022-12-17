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
const int maxn=2e5+5;
int n,a[maxn],b[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();FOR(i,1,n)a[i]=gi(),b[i]=a[i];
}
inline void solve()
{
	int minv=2e9,minpos=0;
	FOR(i,1,n)
	{
		a[i]-=i;
		if(a[i]<minv)minpos=i,minv=a[i];
		if(a[i]-minv>0)
		{
			printf("YES\n%d %d\n",minpos,i);
			return ;
		}
	}
	minv=2e9,minpos=0;
	for(int i=n;i>=1;--i)
	{
		a[i]=b[i];
		a[i]-=(n-i);
		if(a[i]<minv)minpos=i,minv=a[i];
		if(a[i]-minv>0)
		{
			printf("YES\n%d %d\n",i,minpos);
			return ;
		}
	}
	printf("NO\n");
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