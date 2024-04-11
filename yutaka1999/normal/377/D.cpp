#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define SIZE 300100
#define BT 512*1024*2

using namespace std;

struct P
{
	int v,l,r;
	P(int v=0,int l=0,int r=0):v(v),l(l),r(r){}
	bool operator<(const P&q) const
	{
		return l<q.l;
	}
};
struct segtree
{
	int seg[BT],add[BT],pos[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		memset(seg,0,sizeof(seg));
		memset(add,0,sizeof(add));
		for(int i=mum-1;i<mum*2;i++) pos[i]=i-mum+1;
		for(int i=mum-2;i>=0;i--) pos[i]=pos[i*2+1];
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k]+=v;
			add[k]+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			int pl;
			if(seg[k*2+1]>=seg[k*2+2]) pl=k*2+1;
			else pl=k*2+2;
			seg[k]=seg[pl]+add[k];
			pos[k]=pos[pl];
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	int get()
	{
		return seg[0];
	}
	int place()
	{
		return pos[0];
	}
};
segtree seg;
vector <P> add[SIZE],del[SIZE];
P in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int l,v,r;
		scanf("%d %d %d",&l,&v,&r);
		l--;v--;r--;
		P p=P(v,l,r);
		add[l].push_back(p);
		del[v].push_back(p);
		in[i]=p;
	}
	seg.init(SIZE);
	int ret=-1,st=-1,end=-1;
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<add[i].size();j++)
		{
			P p=add[i][j];
			seg.update(p.v,p.r+1,1);
		}
		if(ret<seg.get())
		{
			ret=seg.get();
			st=i;
			end=seg.place();
		}
		for(int j=0;j<del[i].size();j++)
		{
			P p=del[i][j];
			seg.update(p.v,p.r+1,-1);
		}
	}
	printf("%d\n",ret);
	bool f=false;
	for(int i=0;i<n;i++)
	{
		P p=in[i];
		if(p.l<=st&&st<=p.v&&p.v<=end&&end<=p.r)
		{
			if(f) printf(" ");
			printf("%d",i+1);
			f=true;
		}
	}puts("");
	return 0;
}