#pragma GCC optimize("Ofast")
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
const int maxn=1e5+5;
map<int,int>cnt;
int n,a[maxn],b[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	int ans=n;
	FOR(d,-35,35)
	{
		int temp=0;
		map<int,int>cnt;
		FOR(j,1,n)
		{
			temp=a[j]-(j-1)*d;
			cnt[temp]++;
		}
		for(auto x:cnt)ans=min(ans,n-x.second);
	}
	FOR(i,1,n)
	{
		map<int,int>cnt;
		FOR(j,i+1,min(n,i+3002))
		{
			if((a[j]-a[i])%(j-i)==0)
			{
				int t=++cnt[(a[j]-a[i])/(j-i)];
				ans=min(ans,n-1-t);
			}
		}
	}
	printf("%d\n",ans);
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