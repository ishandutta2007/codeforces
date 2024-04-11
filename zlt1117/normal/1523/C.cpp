#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
const int maxn=1e3+5;
int n,a[maxn];
int lst[maxn];
int now=0;
inline void init()
{
	FOR(i,0,n+1)lst[i]=a[i]=0;
	now=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void print()
{
	FOR(i,1,now-1)printf("%d.",lst[i]);
	printf("%d\n",lst[now]);
}
inline void solve()
{
	FOR(i,1,n)
	{
		if(a[i]==1)lst[++now]=1;
		else if(a[i]==lst[now]+1)lst[now]++;
		else 
		{
			while(a[i]!=lst[now]+1)lst[now]=0,now--;
			lst[now]++;
		}
		print();
	}
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