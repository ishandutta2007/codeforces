#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define BT 20
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,ll> P;
typedef pair <ll,P> PP;

struct segtree
{
	vector <PP> seg;//PP(weight,P(city,id))lAmin +  weight+ NGA sum !
	vector <ll> add;
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		seg.resize(mum*2,PP(INF,P(-1,INF)));
		add.resize(mum*2,0);
	}
	void make(int k)
	{
		PP p=min(seg[k*2+1],seg[k*2+2]);
		p.first+=add[k];
		seg[k]=p;
	}
	void update(int a,int b,int k,int l,int r,ll v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k].first+=v;
			add[k]+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			make(k);
		}
	}
	void update(int a,int b,ll v)
	{
		update(a,b,0,0,mum,v);
	}
	void ins(int k,P p)
	{
		k+=mum-1;
		seg[k]=PP(p.second+add[k],p);
		while(k>0)
		{
			k=(k-1)/2;
			make(k);
		}
	}
	ll get(int k)
	{
		k+=mum-1;
		ll ret=add[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret+=add[k];
		}
		return ret;
	}
	PP getmn(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return PP(INF,P(-1,INF));
		if(a<=l&&r<=b) return seg[k];
		else
		{
			PP vl=getmn(a,b,k*2+1,l,(l+r)/2);
			PP vr=getmn(a,b,k*2+2,(l+r)/2,r);
			PP ret=min(vl,vr);
			ret.first+=add[k];
			return ret;
		}
	}
	PP getmn(int a,int b)
	{
		return getmn(a,b,0,0,mum);
	}
};
vector <segtree> seg;
vector <int> vec[SIZE];
vector <int> query[SIZE];
int len[SIZE],id[SIZE];
int nd[SIZE],dep[SIZE];
int par[SIZE][BT];
int back[SIZE],cmb[SIZE];
int pos[SIZE];
int n,m,q;

void dfs(int v=0,int p=-1,int d=0)
{
	par[v][0]=p;
	dep[v]=d;
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v,d+1);
			nd[v]+=nd[to];
		}
	}
}
void heavy_light(int v=0,int p=-1,int bef=-1)
{
	back[v]=bef;
	cmb[v]=seg.size();
	id[v]=len[cmb[v]]++;
	bool up=true;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&nd[to]*2>nd[v])
		{
			up=false;
			heavy_light(to,v,bef);
			break;
		}
	}
	if(up)
	{
		segtree S;
		S.init(len[cmb[v]]+2);
		seg.push_back(S);
	}
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&nd[to]*2<=nd[v])
		{
			heavy_light(to,v,v);
		}
	}
}
void make()
{
	for(int i=0;i+1<BT;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j][i]==-1) par[j][i+1]=-1;
			else par[j][i+1]=par[par[j][i]][i];
		}
	}
}
int LCA(int a,int b)
{
	if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
	for(int i=BT-1;i>=0;i--)
	{
		if(par[b][i]!=-1&&dep[a]<=dep[par[b][i]])
		{
			b=par[b][i];
		}
	}
	if(a==b) return a;
	for(int i=BT-1;i>=0;i--)
	{
		if(par[a][i]!=par[b][i])
		{
			a=par[a][i];
			b=par[b][i];
		}
	}
	return par[a][0];
}
void add_vertex(int v,ll k)
{
	seg[cmb[v]].update(id[v],seg[cmb[v]].mum,k);
}
PP get_min_parent(int v,int p)
{
	PP ret=PP(INF,P(-1,INF));
	while(cmb[v]!=cmb[p])
	{
		ret.first+=seg[cmb[v]].get(id[v]);
		PP mn=seg[cmb[v]].getmn(0,id[v]+1);
		ret=min(ret,mn);
		v=back[v];
	}
	ret.first+=seg[cmb[v]].get(id[v]);
	PP mn=seg[cmb[v]].getmn(id[p],id[v]+1);
	//printf("%d %d: %d %lld\n",id[p],id[v],mn.second.first,mn.second.second);
	return min(ret,mn);
}
ll get_min(int a,int b)
{
	int p=LCA(a,b);
	//PP vl=get_min_parent(a,p),vr=get_min_parent(b,p);
	//printf("%d : %lld %lld : %lld %lld\n",p,vl.first,vl.second.second,vr.first,vr.second.second);
	PP q=min(get_min_parent(a,p),get_min_parent(b,p));
	int v=q.second.first;
	if(v!=-1)
	{
		seg[cmb[v]].ins(id[v],P(v,INF));
		if(pos[v]<query[v].size())
		{
			int r=query[v][pos[v]++];
			//printf("%d %d\n",v,r);
			seg[cmb[v]].ins(id[v],P(v,r));
		}
	}
	return q.second.second;
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	heavy_light();
	make();
	for(int i=0;i<m;i++)
	{
		int c;
		scanf("%d",&c);c--;
		query[c].push_back(i);
	}
	for(int i=0;i<n;i++)
	{
		if(query[i].empty())
		{
			seg[cmb[i]].ins(id[i],P(i,INF));
		}
		else
		{
			int r=query[i][pos[i]++];
			seg[cmb[i]].ins(id[i],P(i,r));
		}
	}
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int a,b,k;
			scanf("%d %d %d",&a,&b,&k);a--;b--;
			vector <ll> ans;
			while(k>0)
			{
				ll g=get_min(a,b);
				if(g>=INF/2) break;
				ans.push_back(g);
				k--;
			}
			printf("%d",ans.size());
			for(int j=0;j<ans.size();j++) printf(" %d",ans[j]+1);
			puts("");
		}
		else
		{
			int v,k;
			scanf("%d %d",&v,&k);v--;
			add_vertex(v,k);
		}
	}
	return 0;
}