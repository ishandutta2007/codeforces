#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1<<19;
int n,k;
struct trie
{
	#define S(u,i) t[u].son[i]
	struct node{int son[2];}t[1<<20];int cnt;
	void insert(int x)
	{
		int u=0;
		for(int i=k-1;i>=0;i--)
		{
			bool now=(x>>i)&1;
			if(!S(u,now))S(u,now)=++cnt;
			u=S(u,now);
		}
	}
	vector<int>mival[1<<20],mxval[1<<20],ansval[1<<20];
	int qrymi(int u,int x,int dep)
	{
		if(dep==-1)return 0;
		if(mival[u].empty())mival[u].resize(1<<(dep+1),-1);
		if(mival[u][x]!=-1)return mival[u][x];
		bool now=(x>>dep)&1;
		if(S(u,now))return mival[u][x]=qrymi(S(u,now),x^(now<<dep),dep-1);
		else return mival[u][x]=qrymi(S(u,!now),x^(now<<dep),dep-1)|(1<<dep);
	}
	int qrymx(int u,int x,int dep)
	{
		if(dep==-1)return 0;
		if(mxval[u].empty())mxval[u].resize(1<<(dep+1),-1);
		if(mxval[u][x]!=-1)return mxval[u][x];
		bool now=(x>>dep)&1;
		if(S(u,!now))return mxval[u][x]=qrymx(S(u,!now),x^(now<<dep),dep-1)|(1<<dep);
		else return mxval[u][x]=qrymx(S(u,now),x^(now<<dep),dep-1);
	}
	int qryans(int u,int x,int dep)
	{
		if(dep==-1)return 1e9;
		if(ansval[u].empty())ansval[u].resize(1<<(dep+1),-1);
		if(ansval[u][x]!=-1)return ansval[u][x];
		bool now=(x>>dep)&1;int ret=1e9;
		x^=(now<<dep);
		if(S(u,0))ret=min(ret,qryans(S(u,0),x,dep-1));
		if(S(u,1))ret=min(ret,qryans(S(u,1),x,dep-1));
		if(S(u,0)&&S(u,1))
		{
			if(!now)ret=min(ret,(1<<dep)+qrymi(S(u,1),x,dep-1)-qrymx(S(u,0),x,dep-1));
			else ret=min(ret,(1<<dep)+qrymi(S(u,0),x,dep-1)-qrymx(S(u,1),x,dep-1));
		}
		return ansval[u][x^(now<<dep)]=ret;
	}
	#undef S
}tr;
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;i++)tr.insert(read());
	for(int i=0;i<(1<<k);i++)printf("%d ",tr.qryans(0,i,k-1));putchar('\n');
	return 0;
}