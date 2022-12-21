//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
#define gc getchar()
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
int T;
char s[maxn];
int cnt1,cnt2,len,ans;
inline void init()
{
	cnt1=cnt2=ans=0;
}
inline void input()
{
	scanf("%s",s+1);
	len=strlen(s+1);
}
inline void solve()
{
	FOR(i,1,len)
	{
		if(s[i]=='(')cnt1++;
		if(s[i]==')')
		{
			if(cnt1)ans++,cnt1--;
		}
		if(s[i]=='[')cnt2++;
		if(s[i]==']')
		{
			if(cnt2)ans++,cnt2--;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}