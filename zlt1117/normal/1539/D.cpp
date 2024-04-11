//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define int ll
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e5+5;
int n,a[maxn],b[maxn],id[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),b[i]=gi();
}
inline void solve()
{
	FOR(i,1,n)id[i]=i;
	sort(id+1,id+n+1,[](int x,int y){return b[x]<b[y];});
	int res=0,ans=0,x=1,y=n;
	while(x<=y)
	{
		int i=id[x],j=id[y];
		if(res+a[j]<=b[i])res+=a[j],y--,ans+=2*a[j],a[j]=0;
		else
		{
			a[j]-=max(0,b[i]-res);
			ans+=2*max(0,b[i]-res);
			res=max(res,b[i]);
			ans+=a[i];x++;
			res+=a[i];a[i]=0;
		}
	}
	printf("%lld\n",ans);
}
signed main()
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