#include<bits/stdc++.h>
using namespace std;
const int N=100100;
struct node
{
	int l,r,minv,maxv;
}t[N<<3]={};
int n,m;
long long h[N+N]={},d[N+N]={},s[N+N]={},s1[N+N]={},s2[N+N]={};
bool cmp1(int a,int b)
{
	return s1[a]<s1[b];
}
bool cmp2(int a,int b)
{
	return s2[a]<s2[b];
}
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,k<<1);
		make_tree(mid+1,r,(k<<1)|1);
		t[k].minv=min(t[k<<1].minv,t[(k<<1)|1].minv,cmp1);
		t[k].maxv=max(t[k<<1].maxv,t[(k<<1)|1].maxv,cmp2);
	}
	else
		t[k].minv=t[k].maxv=l;
	t[k].l=l;
	t[k].r=r;
}
int get_min(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].minv;
	int v=0;
	if(t[k<<1].r>=l)
		v=v==0 ? get_min(l,r,k<<1) : min(v,get_min(l,r,k<<1),cmp1);
	if(t[(k<<1)|1].l<=r)
		v=v==0 ? get_min(l,r,(k<<1)|1) : min(v,get_min(l,r,(k<<1)|1),cmp1);
	return v;
}
int get_max(int l,int r,int k)
{
	if(t[k].l>=l && t[k].r<=r)
		return t[k].maxv;
	int v=0;
	if(t[k<<1].r>=l)
		v=v==0 ? get_max(l,r,k<<1) : max(v,get_max(l,r,k<<1),cmp2);
	if(t[(k<<1)|1].l<=r)
		v=v==0 ? get_max(l,r,(k<<1)|1) : max(v,get_max(l,r,(k<<1)|1),cmp2);
	return v;
}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>d[i];
	for(int i=1;i<=n;++i)
		cin>>h[i];
	copy(d+1,d+n+1,d+n+1);
	copy(h+1,h+n+1,h+n+1);
	for(int i=1;i<=n+n;++i)
		s[i]=s[i-1]+d[i-1];
	for(int i=1;i<=n+n;++i)
		s1[i]=s[i]-h[i]*2;
	for(int i=1;i<=n+n;++i)
		s2[i]=s[i]+h[i]*2;
	/*
	for(int i=1;i<=n+n;++i)
		cout<<s[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n+n;++i)
		cout<<s1[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n+n;++i)
		cout<<s2[i]<<' ';
	cout<<endl;
	*/
	make_tree(1,n+n,1);
}
void work()
{
	int a,b,l,r;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b;
		if(a>b)
			b+=n;
		l=b+1,r=a+n-1;
		//cout<<"l="<<l<<" r="<<r<<endl;
		int p=get_min(l,r-1,1);
		long long ans=0;
		if(l<p)
			ans=max(ans,s2[p]-s1[get_min(l,p-1,1)]);
		if(p<r)
			ans=max(ans,s2[get_max(p+1,r,1)]-s1[p]);
		cout<<ans<<endl;
		//int p1=get_min(l,p,1),p2=get_max(p,r,1);
		//cout<<"p="<<p<<" p1="<<p1<<" p2="<<p2<<endl;
		//cout<<max(s2[p]-s1[p1],s2[p2]-s1[p])<<endl;
	}
}
int main()
{	
	init();
	work();
	return 0;
}