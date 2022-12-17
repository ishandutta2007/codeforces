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
int n,a,b;
inline void init()
{

}
inline void input()
{
	n=gi(),a=gi(),b=gi();
}
inline void solve()
{
	if(a+b>=n-1||abs(a-b)>1)return puts("-1"),void();
	set<int>s;FOR(i,1,n)s.insert(i);
	int p,q;
	if(a==b+1)
	{
		printf("1 ");
		s.erase(1);
		p=2,q=n;
		while(b)
		{
			printf("%d %d ",q,p);
			s.erase(p),s.erase(q);
			p++,q--,a--,b--;
		}
		printf("%d ",q);s.erase(q);
		while(!s.empty())printf("%d ",*--s.end()),s.erase(--s.end());
		puts("");
	}
	else if(b==a+1)
	{
		printf("%d ",n);
		s.erase(n);
		p=1,q=n-1;
		while(a)
		{
			printf("%d %d ",p,q);
			s.erase(p),s.erase(q);
			p++,q--,a--,b--;
		}
		printf("%d ",p);s.erase(p);
		while(!s.empty())printf("%d ",*s.begin()),s.erase(s.begin());
		puts("");
	}
	else 
	{
		p=1,q=n;
		while(a)
		{
			printf("%d %d ",p,q);
			s.erase(p),s.erase(q);
			p++,q--,a--,b--;
		}
		while(!s.empty())printf("%d ",*s.begin()),s.erase(s.begin());
		puts("");
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