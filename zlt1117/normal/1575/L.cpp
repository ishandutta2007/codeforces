#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define mk make_pair
#define iter set<int>::iterator
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5;
int n,a[maxn],c[maxn];
pair<int,int>b[maxn];
int tot;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),b[i]=mk(i-a[i],a[i]);
//	FOR(i,1,n)printf("%d %d %d\n",i,b[i].first,b[i].second);
}
inline void solve()
{
	sort(b+1,b+n+1);
	FOR(i,1,n)
	{
		if(b[i].first<0)continue;
		if(c[tot]<b[i].second)c[++tot]=b[i].second;
		else
		{
			int p=lower_bound(c+1,c+tot+1,b[i].second)-c;
			c[p]=b[i].second;
		}
	}
	printf("%d\n",tot);
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