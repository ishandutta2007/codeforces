#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define pb push_back
char buf[100000],*p1=buf,*p2=buf;
using namespace std;
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e6+5;
bool dp[maxn];
int n;
inline void init()
{

}
inline void input()
{
	n=gi();
	dp[1]=dp[2]=1;
}
inline void solve()
{
	FOR(i,3,n)
	{
		if(i%2==0)
		{
			if(dp[i/2]&&dp[i/2-1])dp[i]=1;
		}
		else 
		{
			int now=i/2;
			if(dp[now]&&now%2==0)dp[i]=1;
		}
	}
	if(dp[n])printf("1\n");
	else printf("0\n");
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///