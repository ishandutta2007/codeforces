#include<bits/stdc++.h>
using namespace std;

struct node
{
	int pos;
	long long d;

	bool operator < (const node &x) const
	{
		return d>x.d;
	}
};

priority_queue<node> q;

int n,m,k;
int to[800020],val[800020],nxt[800020],top[100010],tot;
int v[100020];
long long c[100010];
long long d[100020];
int tr[100010],vvv[100010];

void add_edge(int ff,int tt,int vv)
{
	to[++tot]=tt;
	val[tot]=vv;
	nxt[tot]=top[ff];
	top[ff]=tot;
}

void add(int ff,int tt,int vv)
{
	add_edge(ff,tt,vv);
	add_edge(tt,ff,vv);
}

void spfa(int s)
{
	for(int i=1; i<=n; i++)
	{
		d[i]=0x3f3f3f3f3f3f3f3f;
	}
	d[s]=0;
	c[s]=1;
	q.push({s,0});
	while(!q.empty())
	{
		node u=q.top();
		q.pop();
		if(v[u.pos]) continue;
		v[u.pos]=1;
		for(int i=top[u.pos]; ~i; i=nxt[i])
		{
			if(v[to[i]])
			{
				continue;
			}
			if(d[u.pos]+val[i]<d[to[i]])
			{
				d[to[i]]=d[u.pos]+val[i];
				c[to[i]]=1;
				q.push({to[i],d[to[i]]});
			}
			else
			{
				if(d[u.pos]+val[i]==d[to[i]])
				{
					c[to[i]]+=c[u.pos];
				}
			}
			if(c[to[i]]>k) c[to[i]]=k;
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++) top[i]=-1;
	int ff,tt,vv;
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&ff,&tt,&vv);
		add(ff,tt,vv);
	}
	for(int i=1; i<=k; i++)
	{
		scanf("%d%d",&tr[i],&vvv[i]);
		add(1,tr[i],vvv[i]);
	}
	spfa(1);
	int ans=0;
	for(int i=1; i<=k; i++)
	{
		if(c[tr[i]]>1)
		{
			if(vvv[i]==d[tr[i]]) c[tr[i]]--,ans++;
			else ans++;
		}
		else
		{
			if(vvv[i]>d[tr[i]]) ans++;
		}
	}
	printf("%d\n",ans);
}