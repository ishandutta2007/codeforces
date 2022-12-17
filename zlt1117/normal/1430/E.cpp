#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rd (rand()<<16^rand())
#define pb push_back
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int c[maxn],n;
char s[maxn];
ll ans;
set<int>now[26];
inline void update(int x,int v)
{
	while(x<=n)
	{
		c[x]+=v;
		x+=x&-x;
	}
}
inline int query(int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=x&-x;
	}
	return ret;
}
int main()
{
	n=gi();
	scanf("%s",s+1);
	FOR(i,1,n)now[s[i]-'a'].insert(i);
	reverse(s+1,s+n+1);
	FOR(i,1,n)
	{
		int x=s[i]-'a';
		int curr=*now[x].begin();
		now[x].erase(curr);
		ans+=curr-i+query(curr);
		update(1,1);
		update(curr+1,-1);
	}
	printf("%lld\n",ans);
	return 0;
}
///