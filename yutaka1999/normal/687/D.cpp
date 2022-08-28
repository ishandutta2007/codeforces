#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 1005
#define BT 1024*2*2
#define MX 500005

using namespace std;

struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y])
		{
			par[x]=y;
		}
		else
		{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
struct edge
{
	int start,end;
	int cost;
	edge(int start=-1,int end=-1,int cost=-1):start(start),end(end),cost(cost){}
	bool operator<(const edge&e) const
	{
		if(cost!=e.cost) return cost>e.cost;
		if(start!=e.start) return start>e.start;
		return end>e.end;
	}
};
vector <edge> DMDMD;
struct T
{
	vector <edge> vec;
	int lim;//lim_
	T(int lim=-1,vector <edge> vec=DMDMD):lim(lim),vec(vec){}
};
UF uf;
vector <edge> now;//sort Asort d
vector <int> tree[SIZE];
int col[SIZE];
queue <int> que;
int n,m,q;
T make_Tree(int lim=-1)//nowSAgcalcASerase
{
	uf.init(n+2);
	for(int i=0;i<n;i++)
	{
		tree[i].clear();
		col[i]=-1;
	}
	vector <edge> ret;
	for(int i=0;i<now.size();i++)
	{
		edge e=now[i];
		if(!uf.same(e.start,e.end))
		{
			ret.push_back(e);
			uf.unite(e.start,e.end);
			tree[e.start].push_back(e.end);
			tree[e.end].push_back(e.start);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(col[i]==-1)
		{
			que.push(i);
			col[i]=0;
			while(!que.empty())
			{
				int v=que.front();que.pop();
				for(int j=0;j<tree[v].size();j++)
				{
					int to=tree[v][j];
					if(col[to]==-1)//e
					{
						col[to]=col[v]^1;
						que.push(to);
					}
				}
			}
		}
	}
	for(int i=0;i<now.size();i++)
	{
		edge e=now[i];
		if(col[e.start]==col[e.end])
		{
			lim=max(lim,e.cost);
			break;
		}
	}
	while(!ret.empty())
	{
		edge e=ret[ret.size()-1];
		if(e.cost<=lim) ret.pop_back();
		else break;
	}
	return T(lim,ret);
}
T merge(T &l,T &r)
{
	now.clear();
	int lim=max(l.lim,r.lim);
	int p=0,q=0;
	while(p<l.vec.size()||q<r.vec.size())
	{
		if(q==r.vec.size()||(p<l.vec.size()&&l.vec[p]<r.vec[q]))
		{
			edge e=l.vec[p++];
			if(e.cost<=lim) break;
			now.push_back(e);
		}
		else
		{
			edge e=r.vec[q++];
			if(e.cost<=lim) break;
			now.push_back(e);
		}
	}
	return make_Tree(lim);
}
struct segtree
{
	T seg[BT],ans;
	int mum;
	
	void init(int N)
	{
		mum=1;
		while(mum<N) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=T();
	}
	void ins(int k,T t)
	{
		k+=mum-1;
		seg[k]=t;
	}
	void build()
	{
		for(int i=mum-2;i>=0;i--)
		{
			seg[i]=merge(seg[i*2+1],seg[i*2+2]);
		}
	}
	void get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) ans=merge(ans,seg[k]);
		else
		{
			get(a,b,k*2+1,l,(l+r)/2);
			get(a,b,k*2+2,(l+r)/2,r);
		}
	}
	int get(int l,int r)
	{
		ans=T();
		get(l,r,0,0,mum);
		return ans.lim;
	}
};
segtree seg;
int left[SIZE],right[SIZE];
edge memo[MX];
vector <int> vx;

int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		memo[i]=edge(a,b,c);
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
		left[i]--,right[i]--;
		vx.push_back(left[i]);
		vx.push_back(right[i]+1);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	seg.init(vx.size());
	for(int i=0;i+1<vx.size();i++)
	{
		now.clear();
		for(int j=vx[i];j<vx[i+1];j++) now.push_back(memo[j]);
		sort(now.begin(),now.end());
		seg.ins(i,make_Tree());
	}
	seg.build();
	for(int i=0;i<q;i++)
	{
		int l=lower_bound(vx.begin(),vx.end(),left[i])-vx.begin();
		int r=lower_bound(vx.begin(),vx.end(),right[i]+1)-vx.begin();
		printf("%d\n",seg.get(l,r));
	}
	return 0;
}