#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=5;
class segment_tree
{
	struct node
	{
		int l,r,maxv;
	}t[N<<2];
	int a[N];
	void make_tree(int l,int r,int k)
	{
		if(l!=r)
		{
			int mid=(l+r)>>1;
			make_tree(l,mid,k<<1);
			make_tree(mid+1,r,(k<<1)|1);
			t[k].maxv=max(t[k<<1].maxv,t[(k<<1)|1].maxv);
		}
		else
			t[k].maxv=a[l];
		t[k].l=l;
		t[k].r=r;
	}
	int get_max(int l,int r,int k)
	{
		if(t[k].l>=l && t[k].r<=r)
			return t[k].maxv;
		int v=0;
		if(t[k<<1].r>=l)
			v=max(v,get_max(l,r,k<<1));
		if(t[(k<<1)|1].l<=r)
			v=max(v,get_max(l,r,(k<<1)|1));
		return v;
	}
	public:
	void init_tree(int n)
	{
		make_tree(1,n,1);
	}
	void set_a(int pos,int v)
	{
		a[pos]=v;
	}
	int get_max(int l,int r)
	{
		return get_max(l,r,1);
	}
}T[M];
int n,m,k,v[N][M]={};
void init()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
		for(int j=0;j<m;++j)
			cin>>v[i][j];
	for(int j=0;j<m;++j)
		for(int i=1;i<=n;++i)
			T[j].set_a(i,v[i][j]);
	for(int j=0;j<m;++j)
		T[j].init_tree(n);
}
bool check(int l,int r)
{
	int s=k;
	for(int j=0;j<m;++j)
		if((s-=T[j].get_max(l,r))<0)
			return false;
	return true;
}
void work()
{
	int ansl=n,ansr=0,pos=1;
	for(int i=1;i<=n;++i)
	{
		while(pos<=i && !check(pos,i))
			++pos;
		if(i-pos+1>ansr-ansl+1)
		{
			ansl=pos;
			ansr=i;
		}
	}
	if(ansl>ansr)
		for(int j=0;j<m;++j)
			cout<<0<<' ';
	else		
		for(int j=0;j<m;++j)
			cout<<T[j].get_max(ansl,ansr)<<' ';
	cout<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}