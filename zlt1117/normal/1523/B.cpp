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
const int maxn=1005;
int n,a[maxn];
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
	vector<pair<int,pair<int,int>>>answers;
	for(int i=1;i<=n;i+=2)
	{
		answers.pb({1,{i,i+1}});
		answers.pb({2,{i,i+1}});
		answers.pb({1,{i,i+1}});
		answers.pb({1,{i,i+1}});
		answers.pb({2,{i,i+1}});
		answers.pb({1,{i,i+1}});
	}
	printf("%d\n",sz(answers));
	for(auto x:answers)printf("%d %d %d\n",x.first,x.second.first,x.second.second);
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