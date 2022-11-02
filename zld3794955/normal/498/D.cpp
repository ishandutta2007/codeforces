#include<bits/stdc++.h>
using namespace std;
const int N=100100,V=60,L=0,R=1;
struct node
{
	int l,r,to[V],stops[V],s[2];
}t[N+N]={};
int n,a[N]={},tot=0,root=0;
inline void update(int k)
{
	int k1=t[k].s[L],k2=t[k].s[R];
	for(int i=0;i<V;++i)
	{
		int j=t[k1].to[i];
		t[k].to[i]=t[k2].to[j];
		t[k].stops[i]=t[k1].stops[i]+t[k2].stops[j];
	}
}
inline void calc(int k)
{
	int l=t[k].l;
	for(int i=0;i<V;++i)
		if(i%a[l]==0)
			t[k].to[i]=(i+2)%V,t[k].stops[i]=1;
		else
			t[k].to[i]=(i+1)%V,t[k].stops[i]=0;
}
int make_tree(int l,int r)
{
	int k=++tot;
	t[k].l=l;
	t[k].r=r;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		t[k].s[L]=make_tree(l,mid);
		t[k].s[R]=make_tree(mid+1,r);
		update(k);
	}
	else
		calc(k);
	return k;
}
void change(int pos,int k)
{
	if(t[k].l==t[k].r)
		calc(k);
	else
	{
		t[t[k].s[L]].r>=pos ? change(pos,t[k].s[L]) : change(pos,t[k].s[R]);
		update(k);
	}
}
int get_stops(int l,int r,int k,int &now)
{
	if(t[k].l>=l && t[k].r<=r)
	{
		int ans=t[k].stops[now];
		now=t[k].to[now];
		return ans;
	}
	int s=0;
	if(t[t[k].s[L]].r>=l)
		s+=get_stops(l,r,t[k].s[L],now);
	if(t[t[k].s[R]].l<=r)
		s+=get_stops(l,r,t[k].s[R],now);
	return s;
}
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	root=make_tree(1,n);
}
void work()
{
	int q=0,x,y;
	char c;
	cin>>q;
	for(int i=1;i<=q;++i)
	{
		cin>>c>>x>>y;
		if(c=='C')
		{
			a[x]=y;
			change(x,root);
		}
		else
		{
			int tmp=0;
			printf("%d\n",y-x+get_stops(x,y-1,root,tmp));
		}
	}
}
int main()
{	
	init();
	work();
	return 0;
}