#include<iostream>
#include<cstdio>
using namespace std;
const int M=15000000;
int rt,n,q,m,cnt,lazy[M],l,r,k,tree[M],ls[M],rs[M];
void push(int s,int k,int len){tree[s]=k==1?len:0;}
void down(int s,int len)
{
	if (!lazy[s])return;
	if (!ls[s])ls[s]=++cnt;
	if (!rs[s])rs[s]=++cnt;
	lazy[ls[s]]=lazy[rs[s]]=lazy[s];
	push(ls[s],lazy[s],len-(len>>1));
	push(rs[s],lazy[s],len>>1);
	lazy[s]=0;
}
void insert(int l,int r,int x,int y,int &s,int k)
{
	if (!s)s=++cnt;
	if (l==x&&r==y)
	 {
		lazy[s]=k;
		push(s,k,r-l+1);
		return;
	 }
    down(s,r-l+1);
    int mid=(l+r)>>1;
    if (y<=mid)insert(l,mid,x,y,ls[s],k);
	else if (x>mid)insert(mid+1,r,x,y,rs[s],k);
	else
	 {
    	insert(l,mid,x,mid,ls[s],k);
		insert(mid+1,r,mid+1,y,rs[s],k);
	 }
	tree[s]=tree[ls[s]]+tree[rs[s]];
}
int main()
{
	scanf("%d%d",&n,&m);
	while (m--)
	 {
	 	scanf("%d%d%d",&l,&r,&k);
		insert(1,n,l,r,rt,k);
		printf("%d\n",n-tree[rt]);
	 }
}