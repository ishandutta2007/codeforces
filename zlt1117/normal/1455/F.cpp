#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
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
const int maxn=505;
string dp[maxn];///(next position)
int n,k;
char s[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),k=gi();
	scanf("%s",s+1);
}
inline char pre(char x)
{
	if(x=='a')return 'a'+k-1;
	else return x-1;
}
inline char nxt(char x)
{
	if(x=='a'+k-1)return 'a';
	else return x+1;
}
inline char get(char x){return min(x,min(pre(x),nxt(x)));}
inline void solve()
{
	dp[0]="";
	FOR(i,1,n)
	{
		dp[i]=dp[i-1]+get(s[i]);
		if(i>1)
		{
			string now=dp[i-1]+s[i];
			swap(now[i-1],now[i-2]);
			dp[i]=min(dp[i],now);
			now=dp[i-2]+get(s[i])+s[i-1];
			dp[i]=min(dp[i],now);
		}
		if(i>2)
		{
			string now=dp[i-2]+s[i]+s[i-1];
			swap(now[i-2],now[i-3]);
			dp[i]=min(dp[i],now);
		}
	}
	cout<<dp[n]<<endl;
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
}///