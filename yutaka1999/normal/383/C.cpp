#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 200005
#define BT 256*1028*2

using namespace std;

struct segtree
{
	int seg[BT*2];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]+=v;
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
	int get(int k)
	{
		k+=mum-1;
		int ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret+=seg[k];
		}
		return ret;
	}
};
segtree seg[2];
vector <int> vec[SIZE];
int gen[SIZE];
int cmb[SIZE],id[SIZE];
int now[2],mx[SIZE];
int ld[SIZE],lm[SIZE];

void dfs(int v=0,int p=-1,int c=0)
{
	cmb[v]=c;
	ld[v]=now[c^1];
	id[v]=now[c]++;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs(to,v,c^1);
	}
	lm[v]=now[c^1];
	mx[v]=now[c];
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&gen[i]);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	seg[0].init(n+2);
	seg[1].init(n+2);
	for(int i=0;i<m;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int v,g;
			scanf("%d %d",&v,&g);v--;
			seg[cmb[v]].update(id[v],mx[v],g);
			if(ld[v]!=lm[v]) seg[cmb[v]^1].update(ld[v],lm[v],-g);
		}
		else
		{
			int v;
			scanf("%d",&v);v--;
			int ret=gen[v]+seg[cmb[v]].get(id[v]);
			printf("%d\n",ret);
		}
	}
	return 0;
}