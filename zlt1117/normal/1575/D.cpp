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
const int maxn=15;
char s[maxn],t[maxn];
int n;
inline bool check_vaild(int x)
{
	int len=0;
	if(x==0)t[len=1]='0';
	else while(x)
	{
		t[++len]='0'+x%10;
		x/=10;
	}
	reverse(t+1,t+len+1);
	int xx=-1;
	if(n!=len)return false;
	FOR(i,1,n)
	{
		if(s[i]!='_'&&s[i]!='X')
		{
			if(t[i]!=s[i])return 0;
		}
		if(s[i]=='X')
		{
			if(xx==-1)xx=t[i]-'0';
			else if(t[i]-'0'!=xx)return 0;
		}
	}
	return 1;
}
inline void init()
{

}
inline void input()
{
	scanf("%s",s+1);
	n=strlen(s+1);
}
inline void solve()
{
	int now=0,ans=0;
	while(now<=(int)(1e8))
	{
		if(check_vaild(now))ans++;
		now+=25;
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