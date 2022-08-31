#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#define SIZE 100005
#define BT 1024*128*2
#define MX 1005

using namespace std;
typedef long long int ll;

int n,m;
bool dam[MX];
struct Q
{
	bitset <MX> bit;
	void init()
	{
		bit.reset();
	}
	void add(int k)
	{
		bit.set(k);
	}
	void rot(int k)//0<=k<m
	{
		bit=(bit<<k)|(bit>>(m-k));
	}
};
Q ans;
void merge(Q &L,Q &R,Q &T)
{
	T.bit=L.bit|R.bit;
}
void merge2(Q &L)
{
	ans.bit|=L.bit;
}
struct segtree
{
	Q seg[BT];
	int add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++)
		{
			add[i]=0;
			seg[i].add(0);
		}
	}
	void pass(int k)
	{
		if(add[k]!=0)
		{
			add[k*2+1]+=add[k];
			add[k*2+2]+=add[k];
			if(add[k*2+1]>=m) add[k*2+1]-=m;
			if(add[k*2+2]>=m) add[k*2+2]-=m;
			seg[k*2+1].rot(add[k]);
			seg[k*2+2].rot(add[k]);
			add[k]=0;
		}
	}
	void update(int a,int b,int k,int l,int r,int v)//0<=v<m
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			add[k]+=v;
			if(add[k]>=m) add[k]-=m;
			seg[k].rot(v);
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			merge(seg[k*2+1],seg[k*2+2],seg[k]);
			seg[k].rot(add[k]);
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	void ins(int k,int x)
	{
		update(k,k+1,x);
	}
	void get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) merge2(seg[k]);
		else
		{
			pass(k);
			get(a,b,k*2+1,l,(l+r)/2);
			get(a,b,k*2+2,(l+r)/2,r);
		}
	}
	void get(int a,int b)
	{
		ans.init();
		get(a,b,0,0,mum);
	}
};
segtree seg;
vector <int> vec[SIZE];
int id[SIZE],ch[SIZE];
bool pr[SIZE];
int A[SIZE];
int now_id;

void init()
{
	pr[0]=pr[1]=true;
	for(int i=2;i<SIZE;i++)
	{
		if(!pr[i])
		{
			for(int j=2*i;j<SIZE;j+=i) pr[j]=true;
		}
	}
}
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
	init();
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		A[i]%=m;
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
	for(int i=0;i<n;i++) seg.ins(id[i],A[i]);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int v,x;
			scanf("%d %d",&v,&x);v--;x%=m;
			seg.update(id[v],ch[v],x);
		}
		else
		{
			int v;
			scanf("%d",&v);v--;
			seg.get(id[v],ch[v]);
			int cnt=0;
			for(int j=0;j<m;j++) if(!pr[j]&&ans.bit[j]) cnt++;
			printf("%d\n",cnt);
		}
	}
	return 0;
}