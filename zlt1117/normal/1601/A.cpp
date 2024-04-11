#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=2e5+5;
int cnt[maxn];
int n,a[maxn];
inline void init()
{
	FOR(i,0,30)cnt[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,0,29)
	{
		FOR(j,1,n)
		{
			if(a[j]>>i&1)cnt[i]++;
		}
	}
}
inline void solve()
{
	FOR(i,1,n)
	{
		bool ok=1;
		FOR(j,0,29)
		{
			if(cnt[j]%i!=0)ok=0;
		}
		if(ok)printf("%d ",i);
	}
	puts("");
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