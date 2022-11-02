#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=200020,D=13;
class segment_tree
{
	struct node
	{
		int l,r,maxv;
	}t[M<<2];
	int n;
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
	void change(int pos,int c,int k)
	{
		if(t[k].l==t[k].r)
		{
			t[k].maxv=c;
			return;
		}
		if(t[k<<1].r>=pos)
			change(pos,c,k<<1);
		else
			change(pos,c,(k<<1)|1);
		t[k].maxv=max(t[k<<1].maxv,t[(k<<1)|1].maxv);
	}
	int query(int l,int r,int k)
	{
		if(t[k].l>=l && t[k].r<=r)
			return t[k].maxv;
		int v=0;
		if(t[k<<1].r>=l)
			v=max(v,query(l,r,k<<1));
		if(t[(k<<1)|1].l<=r)
			v=max(v,query(l,r,(k<<1)|1));
		return v;
	}
	public:
	void init(int size) { make_tree(1,n=size,1); }
	void change(int pos,int c) { change(pos,c,1); }
	int query(int l,int r) { return query(l,r,1); }
}Tx,Ty;
map<int,int> s1,s2;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	Tx.init(m+D);
	Ty.init(n);
	for(int i=1,type,p,h,x;i<=m;++i)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d",&p,&h);
			h+=m-i;
			s1[p]=h,s2[h]=p;
			auto t=s2.find(h);
			for(auto it=s2.begin();it!=t;++it)
				Tx.change(it->first,0),Ty.change(it->second,0);
			Tx.change(t->first,0),Ty.change(t->second,0);
			for(auto it=t;it!=s2.begin();--it)
			{
				int tmp=Ty.query(it->second,n)+1;
				Ty.change(it->second,tmp);
				Tx.change(it->first,tmp);
			}
			int tmp=Ty.query(s2.begin()->second,n)+1;
			Ty.change(s2.begin()->second,tmp);
			Tx.change(s2.begin()->first,tmp);
		}
		if(type==2)
		{
			scanf("%d",&x);
			auto t=s1.begin();
			for(int i=1;i<x;++i)
				++t;
			for(auto it=s1.begin();it!=t;++it)
				Tx.change(it->second,0),Ty.change(it->first,0);
			Tx.change(t->second,0),Ty.change(t->first,0);
			
			auto del=*t;
			s1.erase(del.first);
			s2.erase(del.second);
			t=s1.begin();
			for(int i=2;i<x;++i)
				++t;
			if(x>1)
			{
				for(auto it=t;it!=s1.begin();--it)
				{
					int tmp=Tx.query(it->second,m+D)+1;
					Tx.change(it->second,tmp);
					Ty.change(it->first,tmp);
				}
				int tmp=Tx.query(s1.begin()->second,m+D)+1;
				Tx.change(s1.begin()->second,tmp);
				Ty.change(s1.begin()->first,tmp);
			}
		}
		printf("%d\n",Ty.query(1,n));
	}
	return 0;
}