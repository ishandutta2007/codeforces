#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=5005;
char s[maxn];
int n,sum,p[maxn],ans[maxn],sz,len[maxn],dp[maxn];
int now[maxn];
inline int getint()
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
struct PAM
{
	int son[maxn][26],fail[maxn],tot,last,sum[maxn];
	PAM()
	{
		len[1]=-1,len[0]=0;
		fail[1]=0,fail[0]=1;
		tot=1,last=0;
	}
	inline int getfail(int pos,int cur)
	{
		while(s[cur-len[pos]-1]!=s[cur])pos=fail[pos];
		return pos;
	}
	inline void insert(int cur,int c)
	{
		int pos=getfail(last,cur);
		if(!son[pos][c])
		{
			++tot;
			len[tot]=len[pos]+2;
			int newfail=getfail(fail[pos],cur);
			newfail=son[newfail][c];
			fail[tot]=newfail;
			son[pos][c]=tot;
			sum[tot]=sum[newfail]+1;
		}
		last=son[pos][c];
		dp[last]++;
	}
}pam;
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn)
	{
		v=vv,nxt=nn;
	}
}e[maxn<<1];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline void dfs(int u)
{
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		now[len[v]]=now[len[v]/2]+1;
		dfs(v);
		dp[u]+=dp[v];
		ans[now[len[v]]]+=dp[v];
		now[len[v]]=-1;
	}
}
int main()
{
	memset(now,-1,sizeof(now));
	memset(p,-1,sizeof(p));
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{
		pam.insert(i,s[i]-'a');
	}
	for(int i=2;i<=pam.tot;++i)add(pam.fail[i],i);
	dfs(0);
	dfs(1);
	for(int i=n;i>=0;--i)ans[i]+=ans[i+1];
	for(int i=0;i<=n-1;++i)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}