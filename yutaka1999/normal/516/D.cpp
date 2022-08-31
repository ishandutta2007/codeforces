#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
struct BIT
{
	int bit[SIZE];
	int n;
	
	void init(int m)
	{
		n=m;
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		while(k<=n)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int sum(int k)
	{
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};
BIT bit;
vector <edge> vec[SIZE];
priority_queue <ll> que;
ll m1[SIZE],m2[SIZE],p1[SIZE];
int id[SIZE],ch[SIZE];
P pos[SIZE],calc[SIZE];
int now_id,cont;

void dfs(int v,int p)
{
	m1[v]=m2[v]=0;
	id[v]=now_id++;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			dfs(e.to,v);
			ll now=m1[e.to]+(ll) e.cost;
			if(m1[v]<now) swap(m1[v],now);
			if(m2[v]<now) swap(m2[v],now);
		}
	}
	ch[v]=now_id;
}
void make(int v,int p)
{
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			ll now=m1[e.to]+(ll) e.cost;
			if(m1[v]!=now)
			{
				p1[e.to]=m1[v]+e.cost;
				ll vl=p1[e.to];
				if(m1[e.to]<vl) swap(m1[e.to],vl);
				if(m2[e.to]<vl) swap(m2[e.to],vl);
			}
			else
			{
				p1[e.to]=m2[v]+e.cost;
				ll vl=p1[e.to];
				if(m1[e.to]<vl) swap(m1[e.to],vl);
				if(m2[e.to]<vl) swap(m2[e.to],vl);
			}
			make(e.to,v);
		}
	}
}
void insert_get(int v,int p)
{
	que.push(m1[v]);
	cont++;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			insert_get(e.to,v);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	int rt=0;
	for(;rt<n&&vec[rt].size()==1;rt++);
	dfs(rt,-1);
	make(rt,-1);
	p1[rt]=-1;
	for(int i=0;i<n;i++) pos[i]=P(m1[i],i);
	sort(pos,pos+n);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		ll L;
		scanf("%I64d",&L);
		if(rt==n)
		{
			puts("2");
			continue;
		}
		bit.init(n+2);
		int ret=0;
		int e=n-1;
		for(int i=n-1;i>=0;i--)
		{
			while(i<e&&pos[e].first-pos[i].first>L)
			{
				int v=pos[e--].second;
				if(p1[v]==m1[v])
				{
					bit.add(id[v]+1,-1);
				}
			}
			int v=pos[i].second;
			if(p1[v]==m1[v])
			{
				bit.add(id[v]+1,1);
				ret=max(ret,bit.sum(id[v]+1,ch[v]));
			}
		}
		cont=0;
		int v=rt,p=-1;
		while(v!=-1)
		{
			bool up=false;
			int nxt=-1;
			for(int i=0;i<vec[v].size();i++)
			{
				edge e=vec[v][i];
				if(e.to!=p)
				{
					if(!up&&m1[e.to]+e.cost==m1[v])
					{
						up=true;
						nxt=e.to;
					}
				}
			}
			if(up)
			{
				for(int i=0;i<vec[v].size();i++)
				{
					edge e=vec[v][i];
					if(e.to!=p)
					{
						if(e.to!=nxt)
						{
							insert_get(e.to,v);
						}
					}
				}
			}
			else
			{
				for(int i=0;i<vec[v].size();i++)
				{
					edge e=vec[v][i];
					if(e.to!=p)
					{
						if(m1[e.to]>=m1[v])
						{
							insert_get(e.to,v);
						}
					}
				}
			}
			que.push(m1[v]);cont++;
			while(!que.empty()&&que.top()>m1[v]+L)
			{
				cont--;
				que.pop();
			}
			ret=max(ret,cont);
			if(!up)
			{
				int sz=0;
				for(int i=0;i<vec[v].size();i++)
				{
					edge e=vec[v][i];
					if(e.to!=p)
					{
						if(m1[e.to]<m1[v])
						{
							calc[sz++]=P(m1[e.to],e.to);
						}
					}
				}
				sort(calc,calc+sz);
				for(int i=sz-1;i>=0;i--)
				{
					int u=calc[i].second;
					insert_get(u,v);
					while(!que.empty()&&que.top()>m1[u]+L)
					{
						cont--;
						que.pop();
					}
					ret=max(ret,cont);
				}
			}
			p=v;
			v=nxt;
		}
		while(!que.empty()) que.pop();
		printf("%d\n",ret);
	}
	return 0;
}