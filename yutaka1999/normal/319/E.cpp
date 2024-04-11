#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define BT 1024*256*2

using namespace std;
typedef pair <int,int> P;

int memo[SIZE];
int msz;
struct segtree
{
	vector <int> seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i].clear();
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k].push_back(v);
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	void rem(int k)
	{
		for(int i=0;i<seg[k].size();i++)
		{
			int v=seg[k][i];
			memo[msz++]=v;
		}
		seg[k].clear();
	}
	void get(int k)
	{
		msz=0;
		k+=mum-1;
		rem(k);
		while(k>0)
		{
			k=(k-1)/2;
			rem(k);
		}
	}
};
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
	void unite(int x,int y)//x->y
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		par[x]=y;
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
segtree seg;
UF uf;
vector <int> vx;
int T[SIZE],X[SIZE],Y[SIZE];
int id[SIZE];
P pos[SIZE];

P merge(P p,P q)
{
	return P(min(p.first,q.first),max(p.second,q.second));
}
int main()
{
	int n;
	scanf("%d",&n);
	uf.init(n+2);
	int sz=0;
	for(int i=0;i<n;i++)
	{
		int tp,x,y;
		scanf("%d %d %d",&tp,&x,&y);x--;y--;
		T[i]=tp,X[i]=x,Y[i]=y;
		if(tp==1)
		{
			vx.push_back(x);
			vx.push_back(y);
			id[sz++]=i;
		}
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	seg.init(vx.size()+2);
	for(int i=0;i<n;i++)
	{
		if(T[i]==1)
		{
			X[i]=lower_bound(vx.begin(),vx.end(),X[i])-vx.begin();
			Y[i]=lower_bound(vx.begin(),vx.end(),Y[i])-vx.begin();
			pos[i]=P(X[i],Y[i]);
			seg.get(X[i]);
			for(int j=0;j<msz;j++)
			{
				uf.unite(memo[j],i);
				pos[i]=merge(pos[i],pos[memo[j]]);
			}
			seg.get(Y[i]);
			for(int j=0;j<msz;j++)
			{
				uf.unite(memo[j],i);
				pos[i]=merge(pos[i],pos[memo[j]]);
			}
			if(pos[i].first+1<=pos[i].second-1) seg.update(pos[i].first+1,pos[i].second,i);
		}
		else
		{
			int a=id[X[i]],b=id[Y[i]];
			P p=pos[uf.find(b)];
			if((p.first<X[a]&&X[a]<p.second)||(p.first<Y[a]&&Y[a]<p.second)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}