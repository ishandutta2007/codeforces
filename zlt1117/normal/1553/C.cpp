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
int n;
char s[11];
inline void input()
{
	scanf("%s",s+1);
	n=10;
}
int ans=0;
int val[11];
inline int check()
{
	int cnta=0,cntb=0;
	FOR(i,1,10)
	{
		if(i&1)
		{
			if(val[i]==1)cnta++;
			if(cnta>cntb+(11-i)/2)return i;
			if(cntb>cnta+(10-i)/2)return i;
		}
		else
		{
			if(val[i]==1)cntb++;
			if(cntb>cnta+(11-i)/2)return i;
			if(cnta>cntb+(10-i)/2)return i;
		}
	}
	return 10;
}
inline void dfs(int i)
{
	if(i==11)
	{
		ans=min(ans,check());
		return ;
	}
	if(s[i]=='0'||s[i]=='?')val[i]=0,dfs(i+1);
	if(s[i]=='1'||s[i]=='?')val[i]=1,dfs(i+1);
}
inline void solve()
{
	ans=10;
	dfs(1);
	printf("%d\n",ans);
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