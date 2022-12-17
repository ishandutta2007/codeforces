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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int n,k;
inline int query(int x)
{
	printf("%d\n",x);
	fflush(stdout);
	int ret=gi();
	return ret;
}
inline void input()
{
	n=gi();k=gi();
}
inline void solve()
{
	int sum=0;
	FOR(i,0,n-1)
	{
		int x=query(sum^i);
		if(x==1)break;
		else if(x==-1)exit(0);	
		sum=i;
	}
}
int main()
{
	int T=gi();
	while(T--)
	{		
		input();
		solve();
	}
	return 0;
}