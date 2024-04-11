#include<stdio.h>
#include<cstring>
#include<algorithm>
#define lowbit(o) (o&(-o))
#define maxn 500005
using namespace std;
struct node
{
    int next,to,num;
}a[maxn*2];
struct gtw
{
	int val;
}tree[4000005],aa[4000005];
int gt,d[4000005];
int q[maxn],fa[maxn];
bool visit[maxn];
int i,j,k,l,s,m,n,tot,x,y;
int st[maxn],en[maxn];
int last[maxn];
inline void up(int o)
{
	tree[o].val=max(tree[o*2].val,tree[o*2+1].val);
}
inline void up1(int o)
{
	aa[o].val=max(aa[o*2].val,aa[o*2+1].val);
}
inline void down(int o)
{
	d[o*2]=tree[o*2].val=d[o];
	d[o*2+1]=tree[o*2+1].val=d[o];
	d[o]=0;
}
inline void change(int o,int l,int r,int ll,int rr,int gtw)
{
	if (l==ll&&r==rr)
	{
		tree[o].val=gtw;
		d[o]=gtw;
		return ;
	}
	if (d[o])
	down(o);
	int mid=(l+r)>>1;
	if (mid>=rr)
	change(o*2,l,mid,ll,rr,gtw);
	else
	if (mid<ll)
	change(o*2+1,mid+1,r,ll,rr,gtw);
	else
	{
		change(o*2,l,mid,ll,mid,gtw);
		change(o*2+1,mid+1,r,mid+1,rr,gtw);
	}
	up(o);
}
inline void change1(int o,int l,int r,int ll,int rr,int gtw)
{
	if (l==ll&&r==rr)
	{
		aa[o].val=gtw;
		return ;
	}
	int mid=(l+r)>>1;
	if (mid>=rr)
	change1(o*2,l,mid,ll,rr,gtw);
	else
	if (mid<ll)
	change1(o*2+1,mid+1,r,ll,rr,gtw);
	else
	{
		change1(o*2,l,mid,ll,mid,gtw);
		change1(o*2+1,mid+1,r,mid+1,rr,gtw);
	}
	up1(o);
}
inline int ask(int o,int l,int r,int ll,int rr)
{
	if (l==ll&&r==rr)
	return tree[o].val;
	if (d[o])
	down(o);
	int mid=(l+r)>>1;
	if (mid>=rr)
	return ask(o*2,l,mid,ll,rr);
	else
	if (mid<ll)
	return ask(o*2+1,mid+1,r,ll,rr);
	else
	{
		int gt=0;
		gt=ask(o*2,l,mid,ll,mid);
		gt=max(gt,ask(o*2+1,mid+1,r,mid+1,rr));
		return gt;
	}
}
inline int ask1(int o,int l,int r,int ll,int rr)
{
	if (l==ll&&r==rr)
	return aa[o].val;
	int mid=(l+r)>>1;
	if (mid>=rr)
	return ask1(o*2,l,mid,ll,rr);
	else
	if (mid<ll)
	return ask1(o*2+1,mid+1,r,ll,rr);
	else
	{
		int gt=0;
		gt=ask1(o*2,l,mid,ll,mid);
		gt=max(gt,ask1(o*2+1,mid+1,r,mid+1,rr));
		return gt;
	}
}
inline void build(int o,int l,int r)
{
	if (l==r)
	{
		tree[o].val=0;
		aa[o].val=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
	up(o);
}
inline void add(int o,int p)
{
    tot++;
    a[tot].next=last[o];
    last[o]=tot;
    a[tot].to=p;
    tot++;
    a[tot].next=last[p];
    last[p]=tot;
    a[tot].to=o;
}
inline void dfsxu(int o)
{
    tot++;
    st[o]=tot;
    for (int i=last[o];i;i=a[i].next)
    {
        if (fa[a[i].to]==o)
        dfsxu(a[i].to);
    }
    tot++;
    en[o]=tot;
}
inline void bfs(int o)
{
       int l=0,r=1;
       q[1]=o;
       while (l<=r)
       {
             int k=q[++l];
             for (int i=last[k];i;i=a[i].next)
             if (fa[k]!=a[i].to)
             {
                fa[a[i].to]=k;
                q[++r]=a[i].to;
             }
       }
}
inline int in()
{
    char ch;  
    bool f=false;
    int a=0;  
    while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));  
    if(ch!='-')a*=10,a+=ch-'0';else f=true;
    while(((ch=getchar())>='0')&&(ch<='9'))a*=10,a+=ch-'0';  
    if(f)a=-a;
    return a;  
}
int main()
{
    n=in();
    for (i=1;i<n;i++)
    {
        x=in();y=in();
        add(x,y);
    }
    bfs(1);
    visit[1]=true;
    tot=0;
    dfsxu(1);
    build(1,1,tot);
    m=in();
    gt=1;
    for (i=1;i<=m;i++)
    {
    	x=in();y=in();
    	if (x==1)
    	change(1,1,tot,st[y],en[y],++gt);
    	else
    	if (x==2)
    	{
    		change1(1,1,tot,st[y],st[y],++gt);
    		change1(1,1,tot,en[y],en[y],gt);
    	}
    	else
    	{
    		int yy=ask(1,1,tot,st[y],st[y]);
    		int yyy=ask1(1,1,tot,st[y],en[y]);
    		if (yy>yyy)
    		printf("1\n");
    		else
    		printf("0\n");
    	}
    }		
}