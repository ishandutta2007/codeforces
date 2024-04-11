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
const int maxn=2e5+5;
int n,k,x,a[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),k=gi(),x=gi();
	FOR(i,1,n)a[i]=gi();
	sort(a+1,a+n+1);
}
inline void solve()
{
	int res=n;
	vector<int>v;
	FOR(i,2,n)v.pb(max(0,(a[i]-a[i-1]-1)/x));
	sort(v.begin(),v.end());
	for(int x:v)
	{
		if(k>=x)res--,k-=x;
		else break;
	}
	printf("%lld\n",res);
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