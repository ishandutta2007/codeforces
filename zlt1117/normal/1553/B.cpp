#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define PII pair<int,int>
#define sz(x) (int)(x.size())
#define mk make_pair
#define pb push_back
#define iter set<int>::iterator
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1005;
int lens,lent;
char s[maxn],t[maxn];
inline void input()
{
	scanf("%s",s+1),scanf("%s",t+1);
	lens=strlen(s+1),lent=strlen(t+1);
}
inline bool check(int x,int y)
{
	if(y+y-x<lent)return false;
	int cnt=0;
	FOR(i,x,y)
	{
		if(t[++cnt]!=s[i])return false;
		if(cnt==lent)return true;
	}
	for(int i=y-1;i>=1;--i)
	{
		if(t[++cnt]!=s[i])return false;
		if(cnt==lent)return true;
	}
	return false;
}
inline void solve()
{
	FOR(i,1,lens)
	{
		FOR(j,i,lens)
		{
			if(check(i,j))return puts("Yes"),void();
		}
	}
	puts("No");
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