#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=4000005, M=20000005;

namespace IO {
	inline char nc(){
		static char buf[500001],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,500000,stdin),p1==p2)?EOF:*p1++;
	}
	char out[500001],*pout=out,*eout=out+500000;
	template<typename T> inline T read(){
		char ch=nc(); T sum=0; bool f=false;
		for(;ch<'0'||ch>'9';ch=nc()) if(ch=='-') f=1;
		while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
		return f ? -sum : sum;
	}
}
#define read IO::read<int>

int n, m, ans;
int stk[N], dfn[N], low[N], deg[N], cnt, top;
int head[N], nxt[M], to[M];
void tarjan(int u, int fa)
{
	ans+=deg[u]/2;
	stk[++top]=u;
	dfn[u]=low[u]=++cnt;
	int is=0;
	for(int i=head[u]; i; i=nxt[i])
	{
		int v=to[i];
		if(v!=fa||is)
		{
			if(!dfn[v])
			{
				tarjan(v, u);
				low[u]=std::min(low[u], low[v]);
			}
			else low[u]=std::min(low[u], low[v]);
		}
		else is=1;
	}
	if(low[u]==dfn[u])
	{
		int tot=0, ct=0;
		while(stk[top+1]!=u)
		{
			int x=stk[top--];
			++tot;
			ct+=deg[x]>2;
		}
//		printf("fa %d %d %d %d\n", u, tot, odd, ct);
		if(tot>1&&ct<2) --ans;
	}
}
int tot;
inline void adde(int x, int y)
{
	nxt[++tot]=head[x], to[tot]=y;
	head[x]=tot;
	++deg[x];
}
int main()
{
	n=read(), m=read();
	for(int i=1, x, y; i<=m; ++i) x=read(), y=read(), adde(x, y), adde(y, x);
//	return 0;
	tarjan(1, 0);
	printf("%d %d\n", m-ans, m);
	return 0;
}