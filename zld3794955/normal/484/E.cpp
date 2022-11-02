#include<iostream>
#include<cstdio>
#include<cassert>
#include<algorithm>
using namespace std;
const int N=100010,D=22,L=0,R=1;
struct node
{
	int l,r,ls,rs,maxl,s[2];
}t[N*D]={};
pair<int,int> wall[N];
int n,p=0,root[N]={},tot=0;
inline int set_newnode(int l,int r,int d,int s1,int s2)
{
	t[++tot]=(node){l,r,d,d,d,{s1,s2}};
	return tot;
}
int make_tree(int l,int r)
{
	if(l==r)
		return set_newnode(l,r,0,0,0);
	int mid=(l+r)>>1;
	return set_newnode(l,r,0,make_tree(l,mid),make_tree(mid+1,r));
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&wall[i].first);
		wall[i].second=i;	
	}
}
inline bool full(const node& t)
{
	return t.maxl==t.r-t.l+1;
}
node merge(const node &n1,const node &n2)
{
	node now;
	now.ls=n1.ls , now.rs=n2.rs;
	if(full(n1)) now.ls+=n2.ls;
	if(full(n2)) now.rs+=n1.rs;
	now.l=n1.l , now.r=n2.r;
	now.maxl=max(n1.maxl,n2.maxl);
	now.maxl=max(now.maxl , n1.rs+n2.ls);
	return now;
}
void update(int k)
{
	t[k].ls=t[t[k].s[L]].ls;
	if(full(t[t[k].s[L]]))
		t[k].ls+=t[t[k].s[R]].ls;
	t[k].rs=t[t[k].s[R]].rs;
	if(full(t[t[k].s[R]]))
		t[k].rs+=t[t[k].s[L]].rs;
	t[k].maxl=max(t[t[k].s[L]].maxl , t[t[k].s[R]].maxl);
	t[k].maxl=max(t[k].maxl , t[t[k].s[L]].rs+t[t[k].s[R]].ls);
}
int insert(int k,int pos)
{
	if(t[k].l==t[k].r)
		return set_newnode(t[k].l,t[k].r,1,0,0);
	int mid=(t[k].l+t[k].r)>>1;
	int now=insert(t[k].s[pos>mid],pos),p=0;
	if(pos<=mid)
		p=set_newnode(t[k].l,t[k].r,0,now,t[k].s[R]);
	else
		p=set_newnode(t[k].l,t[k].r,0,t[k].s[L],now);
	update(p);
	return p;
}
void insert()
{
	root[n+1]=make_tree(1,n);
	sort(wall+1,wall+n+1);
	for(int i=n;i>=1;--i)
		root[i]=insert(root[i+1],wall[i].second);
}
node get_seg(int k,int tl,int tr)
{
	if(t[k].l>=tl && t[k].r<=tr)
		return t[k];
	if(t[t[k].s[L]].r>=tl && t[t[k].s[R]].l<=tr)
		return merge( get_seg(t[k].s[L],tl,tr) , get_seg(t[k].s[R],tl,tr) );
	if(t[t[k].s[L]].r<tl && t[t[k].s[R]].l<=tr)
		return get_seg(t[k].s[R],tl,tr);
	if(t[t[k].s[L]].r>=tl && t[t[k].s[R]].l>tr)
		return get_seg(t[k].s[L],tl,tr);
	assert(false);
}
int get_ans(int ll,int rr,int sl)
{
	int l=1,r=n,mid=0;
	for(;l!=r; get_seg(root[mid=(l+r+1)>>1],ll,rr).maxl>=sl? l=mid :r=mid-1);
	return wall[l].first;
}
void work()
{
	int q,l,r,w;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d%d",&l,&r,&w);
		printf("%d\n",get_ans(l,r,w));
	}
}
int main()
{	
	init();
	insert();
	work();
	return 0;
}