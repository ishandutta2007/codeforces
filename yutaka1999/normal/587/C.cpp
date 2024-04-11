#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define SIZE 100005
#define BT 20
#define BB 1024*128*2

using namespace std;
typedef pair <int,int> P;

struct segtree
{
	P seg[BB];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=P(BB,0);
	}
	void add(int k,int x)
	{
		seg[k+mum-1]=P(x,k);
		k+=mum-1;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	P get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return P(BB,-1);
		if(a<=l&&r<=b) return seg[k];
		else
		{
			P vl=get(a,b,k*2+1,l,(l+r)/2);
			P vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}
	P pos(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
vector <int> vec[SIZE];
vector <int> query[SIZE];
int par[SIZE][BT],dep[SIZE];
int V[SIZE],U[SIZE],A[SIZE],T[SIZE];
vector <int> ans[SIZE];
vector <int> nm[SIZE];
int pl[SIZE],wh[SIZE];
int memo[SIZE];
int n,m,q;

void dfs(int v=0,int p=-1,int d=0)
{
	par[v][0]=p;
	dep[v]=d;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v,d+1);
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
		if(par[b][i]!=-1&&dep[par[b][i]]>=dep[a])
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
void solve(int v=0,int p=-1)
{
	seg.add(dep[v],nm[v][0]);
	wh[dep[v]]=v;
	for(int i=0;i<query[v].size();i++)
	{
		int id=query[v][i];
		int sz=0;
		while(sz<A[id])
		{
			P q=seg.pos(dep[T[id]],dep[v]+1);
			if(q.first==BB) break;
			ans[id].push_back(q.first);
			int t=wh[q.second];
			memo[sz++]=q.second;
			seg.add(q.second,nm[t][++pl[t]]);
		}
		for(int j=sz-1;j>=0;j--)
		{
			int x=wh[memo[j]];
			seg.add(memo[j],nm[x][--pl[x]]);
		}
	}
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) solve(to,v);
	}
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
	for(int i=0;i<m;i++)
	{
		int c;
		scanf("%d",&c);c--;
		nm[c].push_back(i);
	}
	for(int i=0;i<n;i++) nm[i].push_back(BB);
	dfs();
	make();
	for(int i=0;i<q;i++)
	{
		scanf("%d %d %d",&V[i],&U[i],&A[i]);
		V[i]--;U[i]--;
		int p=LCA(V[i],U[i]);
		T[i]=p;
		query[V[i]].push_back(i);
		query[U[i]].push_back(i);
	}
	seg.init(n+2);
	memset(pl,0,sizeof(pl));
	solve();
	for(int i=0;i<q;i++)
	{
		sort(ans[i].begin(),ans[i].end());
		ans[i].erase(unique(ans[i].begin(),ans[i].end()),ans[i].end());
		int mn=min((int) ans[i].size(),A[i]);
		printf("%d",mn);
		for(int j=0;j<mn;j++) printf(" %d",ans[i][j]+1);
		puts("");
	}
	return 0;
}