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
#define mk make_pair
#define iter set<int>::iterator
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
int n;
inline ll query(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	ll ret=0;
	scanf("%lld",&ret);
	return ret;
}
inline void init()
{

}
inline void input()
{
	n=gi();
}
inline void solve()
{
	int l=1,r=n,ans=1;
	ll tot=query(l,r);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(query(mid,n)!=tot)r=mid-1;
		else ans=mid,l=mid+1;
	}
	int posi=ans;
	int now=tot-query(posi+1,n);
	int posj=posi+now;
	ll sum=1ll*now*(now+1)/2;
	tot-=sum;tot*=2;
	l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(1ll*mid*(mid-1)>tot)r=mid-1;
		else ans=mid,l=mid+1;
	}
	int posk=posj+ans;
	printf("! %d %d %d\n",posi,posj+1,posk);
	fflush(stdout);
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}