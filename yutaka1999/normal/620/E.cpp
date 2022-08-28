#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 400005
#define BT 512*1024*2

using namespace std;
typedef long long int ll;

struct segtree
{
	ll seg[BT];
	bool use[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			use[i]=false;
			seg[i]=0;
		}
	}
	void pass(int k)
	{
		if(use[k])
		{
			seg[k*2+1]=seg[k*2+2]=seg[k];
			use[k*2+1]=use[k*2+2]=true;
			use[k]=false;
		}
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]=1LL<<v;
			use[k]=true;
		}
		else
		{
			pass(k);
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=seg[k*2+1]|seg[k*2+2];
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	void add(int k,int x)
	{
		update(k,k+1,x);
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			pass(k);
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return vl|vr;
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
vector <int> vec[SIZE];
int id[SIZE],ch[SIZE];
int col[SIZE];
int now_id;

void dfs(int v=0,int p=-1)
{
	id[v]=now_id++;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs(to,v);
	}
	ch[v]=now_id;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&col[i]);
		col[i]--;
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	seg.init(n+2);
	for(int i=0;i<n;i++) seg.add(id[i],col[i]);
	for(int i=0;i<m;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int v,c;
			scanf("%d %d",&v,&c);v--;c--;
			seg.update(id[v],ch[v],c);
		}
		else
		{
			int v;
			scanf("%d",&v);v--;
			ll gt=seg.get(id[v],ch[v]);
			int cnt=0;
			for(int j=0;j<60;j++) if(gt>>j&1) cnt++;
			printf("%d\n",cnt);
		}
	}
	return 0;
}