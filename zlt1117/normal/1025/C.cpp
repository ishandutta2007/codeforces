//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int n;
char s[maxn];
inline void init()
{

}
inline void input()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n)s[i+n]=s[i];
	n*=2;
}
inline void solve()
{
	int ans=0;
	int sum=1;
	FOR(i,2,n)
	{
		if(s[i]!=s[i-1])sum++;
		else 
		{
			ans=max(ans,sum);
			sum=1;
		}
	}
	ans=max(ans,sum);
	printf("%d\n",min(ans,n/2));
}
int main()
{
	init();
	input();
	solve();
	return 0;
}