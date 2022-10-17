#include<bits/stdc++.h>
#define N 100100
using namespace std;

int n,m,c,Q,fa[N];
char str[5];
map<int,int>pos[N];
set<int>have[N];
set<int>::iterator it;

int ff(int u){return u==fa[u]?u:fa[u]=ff(fa[u]);}
inline void mg(int u,int v)
{
    u=ff(u),v=ff(v);
    if(u==v) return;
    if(have[u].size()>have[v].size()) swap(u,v);
    for(it=have[u].begin();it!=have[u].end();it++) have[v].insert(*it);
    fa[u]=v;
}

inline void add(int u,int v,int w)
{
    if(pos[u].count(w)) mg(pos[u][w],v);
    else pos[u][w]=v;
    if(pos[v].count(w)) mg(pos[v][w],u);
    else pos[v][w]=u;
    have[ff(u)].insert(v);
    have[ff(v)].insert(u);
}

int main()
{
    int i,j,p,q,o;
    cin>>n>>m>>c>>Q;
    for(i=1;i<=n;i++) fa[i]=i;
    for(i=1;i<=m;i++)
    {
	scanf("%d%d%d",&p,&q,&o);
	add(p,q,o);
    }
    while(Q--)
    {
	scanf("%s%d%d",str+1,&p,&q);
	if(str[1]=='?')
	{
	    p=ff(p);
	    if(p==ff(q) || have[p].find(q)!=have[p].end()) puts("Yes");
	    else puts("No");
	}
	else
	{
	    scanf("%d",&o);
	    add(p,q,o);
	}
    }
}