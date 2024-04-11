#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef long double LD;
const int N=400010;
struct node
{
    int l,r,fa; //son
    int cnt; //size
    int key; //randomkey
	int p,v;
	void init(int _v){p=0;v=_v;l=r=fa=0;cnt=1;key=rand()*rand();}
}a[N];
int root;
void update(int x)
{
    int l=a[x].l,r=a[x].r;
    a[x].cnt=a[l].cnt+a[r].cnt+1;
    if(l)a[l].fa=x;
    if(r)a[r].fa=x;
    a[x].fa=0;
}
void cov(int x,int v)
{
	a[x].p=a[x].v=v;
}
void pushdown(int x)
{
	if(!a[x].p)return;
    int l=a[x].l,r=a[x].r,p=a[x].p;
    if (l!=0)a[l].p=p,a[l].v=p;
    if (r!=0)a[r].p=p,a[r].v=p;
    a[x].p=0;
}
int merge(int x,int y)
{
    if (x==0||y==0)return x+y;
    if (a[x].p)pushdown(x);
    if (a[y].p)pushdown(y);
    if (a[x].key>a[y].key)
    {
        a[x].r=merge(a[x].r,y);
        update(x);
        return x;
    }
    else
    {
        a[y].l=merge(x,a[y].l);
        update(y);
        return y;
    }
}
void split(int t,int k,int &x,int &y)
{
    if (t==0){x=0; y=0; return;}
    if (a[t].p)pushdown(t);
    if (a[a[t].l].cnt+1<=k)
    {
        x=t;
        split(a[t].r,k-a[a[t].l].cnt-1,a[t].r,y);
    }
    else
    {
        y=t;
        split(a[t].l,k,x,a[t].l);
    }
    if (x!=0)update(x);
    if (y!=0)update(y);
}
int getpos(int x)
{
	int res=a[a[x].l].cnt+1;
	for(;a[x].fa;x=a[x].fa)if(a[a[x].fa].r==x)res+=a[a[a[x].fa].l].cnt+1;
	return res;
}
int getnum(int x)
{
	int p=root,res=0;
	for(;p;)
	{
		pushdown(p);
		if(a[p].v<=x)res+=a[a[p].l].cnt+1,p=a[p].r;
		else p=a[p].l;
	}
	return res;
}
int n,q,p[N];
int main()
{
	srand(19260817);
	scanf("%d",&n);
	rep(i,n){int x;scanf("%d",&x);a[i].init(x);p[i]=i;}
	sort(p+1,p+n+1,[&](int x,int y){return a[x].v<a[y].v;});
	rep(i,n)root=merge(root,p[i]);
	scanf("%d",&q);
	rep(i,q)
	{
		int opt,k,w,l,r;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&k,&w);
			int t1,t2,t3,pos=getpos(k);
			split(root,pos-1,t1,t2);
			split(t2,1,t2,t3);
			root=merge(t1,t3);
			cov(t2,w);
			pos=getnum(w);
			split(root,pos,t1,t3);
			root=merge(merge(t1,t2),t3);
		}
		else if(opt==2)
		{
			scanf("%d",&k);
			int t1,t2,t3,pos=getpos(k);
			split(root,pos-1,t1,t2);
			split(t2,1,t2,t3);
			printf("%d\n",a[t2].v);
			root=merge(merge(t1,t2),t3);
		}
		else
		{
			scanf("%d%d",&l,&r);
			int mid=(l+r)>>1;
			int p1=getnum(l-1),p2=getnum(mid),p3=getnum(r);
			int t1,t2,t3,t4;
			split(root,p1,t1,t2);
			split(t2,p2-p1,t2,t3);
			split(t3,p3-p2,t3,t4);
			cov(t2,l-1);
			cov(t3,r+1);
			root=merge(merge(t1,t2),merge(t3,t4));
		}
	}
    return 0;
}