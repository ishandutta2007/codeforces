#include<bits/stdc++.h>
using namespace std;
const int Q=200020;
class segment_tree
{
	struct node
	{
		int l,r,maxv;
	}t[Q<<2];
	void make_tree(int l,int r,int k)
	{
		if(l!=r)
		{
			int mid=(l+r)>>1;
			make_tree(l,mid,k<<1);
			make_tree(mid+1,r,(k<<1)|1);
		}
		t[k].l=l;
		t[k].r=r;
		t[k].maxv=0;
	}
	int get_max(int pos,int k)
	{
		if(t[k].l==t[k].r)
			return t[k].maxv;
		if(t[k<<1].r>=pos)
			return max(t[k].maxv,get_max(pos,k<<1));
		else
			return max(t[k].maxv,get_max(pos,(k<<1)|1));
	}
	void change(int l,int r,int c,int k)
	{
		if(t[k].l>=l && t[k].r<=r)
		{
			t[k].maxv=max(t[k].maxv,c);
			return;
		}
		if(t[k<<1].r>=l)
			change(l,r,c,k<<1);
		if(t[(k<<1)|1].l<=r)
			change(l,r,c,(k<<1)|1);
	}
	public:
	void init(int size) { make_tree(1,size,1); }
	void change(int l,int r,int c) { change(l,r,c,1); }
	int get_max(int pos) { return get_max(pos,1); }
}Tx,Ty;
int n,q,tx=0,ty=0,vx[Q]={},vy[Q]={};
int x[Q]={},y[Q]={};
char type[Q]={};
void init()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d\n%c",x+i,y+i,type+i);
		vx[++tx]=x[i];
		vy[++ty]=y[i];
	}
	sort(vx+1,vx+tx+1);
	sort(vy+1,vy+ty+1);
	Tx.init(q);
	Ty.init(q);
	for(int i=1;i<=q;++i)
	{
		x[i]=lower_bound(vx+1,vx+tx+1,x[i])-vx;
		y[i]=lower_bound(vy+1,vy+ty+1,y[i])-vy;
	}
}
void work()
{
	for(int i=1;i<=q;++i)
		if(type[i]=='U')
		{
			int tmp=Tx.get_max(x[i]);
			printf("%d\n",vy[y[i]]-vy[tmp]);
			Ty.change(tmp,y[i],x[i]);
			Tx.change(x[i],x[i],y[i]);
		}
		else
		{
			int tmp=Ty.get_max(y[i]);
			printf("%d\n",vx[x[i]]-vx[tmp]);
			Tx.change(tmp,x[i],y[i]);
			Ty.change(y[i],y[i],x[i]);
		}
}
int main()
{
	init();
	work();
	return 0;
}