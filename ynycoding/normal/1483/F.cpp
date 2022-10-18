#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
using std::queue;
using std::vector;
const int N=2000005;
int nxt[N][26], up[N], is[N], ok[N], fail[N], cnt, in[N], out[N], top;
vector<int> e[N];
inline void insert(char *s, int n)
{
	static int debug=0;//
	int idx=0;
	for(int i=1; i<=n; ++i)
	{
		if(!nxt[idx][s[i]-'a']) nxt[idx][s[i]-'a']=++top;
		idx=nxt[idx][s[i]-'a'];
	}
	is[idx]=++debug;
//	is[idx]=1;
}
void dfs(int u)
{
	in[u]=++cnt;
	for(int v:e[u])
		dfs(v);
	out[u]=cnt;
}
void build(void)
{
	queue<int> q;
	for(int i=0; i<26; ++i) if(nxt[0][i]) q.push(nxt[0][i]);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0; i<26; ++i)
		{
			(nxt[u][i]?q.push(nxt[u][i]), fail[nxt[u][i]]:nxt[u][i])=nxt[fail[u]][i];
		}
		if(!is[u]) up[u]=up[fail[u]];
		else up[u]=u;
		e[fail[u]].pb(u);
	}
	dfs(0);
}
int sum[N], sum1[N];
inline void add(int p, int x) { while(p<=cnt) sum[p]+=x, p+=p&(-p); }
inline int ask(int p) { int ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
inline void add1(int p, int x) { while(p<=cnt) sum1[p]+=x, p+=p&(-p); }
inline int ask1(int p) { int ret=0; while(p) ret+=sum1[p], p-=p&(-p); return ret; }
int n, len[N], rid[N], stk[N][2], ans;
char *s[N], pool[N], *cur=pool;
inline void ins(int x)
{
//	printf("ins %d\n", x);
	add(in[x], x);
	add(out[x]+1, -x);
	add1(in[x], 1);
}
inline void del(int x)
{
//	printf("del %d\n", x);
	add(in[x], -x);
	add(out[x]+1, x);
	add1(in[x], -1);
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		s[i]=cur;
		scanf("%s", s[i]+1);
		len[i]=strlen(s[i]+1);
		insert(s[i], len[i]);
		cur+=len[i]+1;
	}
	build();
//	return 0;
	for(int i=1; i<=n; ++i)
	{
		int idx=0;
		for(int j=1; j<=len[i]; ++j)
		{
			idx=nxt[idx][s[i][j]-'a'];
			int v=j==len[i]?up[fail[idx]]:up[idx];
			rid[j]=v;
			int id=ask(in[v]), id1=ask1(out[v])-ask1(in[v]-1);
			if(!id1&&v)
			{
				if(id)
				{
					del(id);
					ok[id]=0;
				}
				ins(v);
				ok[v]=1;
			}
		}
		top=0;
		int ret=0;
//		for(int j=1; j<=len[i]; ++j) if(ok[rid[j]]) printf("ok %d\n", is[rid[j]]);
		for(int j=1; j<=len[i]; ++j)
		{
			int v=rid[j];
			if(ok[v])
			{
				int pr=j-len[is[v]];
				while(top&&stk[top][1]>=pr)
				{
					if(ok[stk[top][0]]) del(stk[top][0]);
					ok[stk[top][0]]=0;
					--top;
				}
				stk[++top][0]=v, stk[top][1]=pr;
			}
		}
//		for(int j=1; j<=len[i]; ++j) if(ok[rid[j]]) printf("rok %d\n", is[rid[j]]);
		for(int j=1; j<=len[i]; ++j)
		{
			int v=rid[j];
			if(ok[v])
			{
				++ret;
				del(v);
				ok[v]=0;
			}
		}
//		printf("ret %d %d\n", i, ret);
		ans+=ret;
	}
	printf("%d\n", ans);
	return 0;
}