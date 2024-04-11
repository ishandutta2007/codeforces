#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int,int> pii;
int n;
int mod;
struct mat
{
	int a[2][2];
	mat()
	{
		memset(a,0,sizeof a);
	}
	void init()
	{
		a[0][0]=a[1][1]=1;
		a[0][1]=a[1][0]=0;
	}
	int* operator [](int x)
	{
		return a[x];
	}
};
mat f[100010];
mat operator *(const mat &a,const mat &b)
{
	mat c;
	c.a[0][0]=(a.a[0][0]*b.a[0][0]+a.a[0][1]*b.a[1][0])%mod;
	c.a[0][1]=(a.a[0][0]*b.a[0][1]+a.a[0][1]*b.a[1][1])%mod;
//	c.a[1][0]=(a.a[1][0]*b.a[0][0]+a.a[1][1]*b.a[1][0])%mod;
//	c.a[1][1]=(a.a[1][0]*b.a[0][1]+a.a[1][1]*b.a[1][1])%mod;
	return c;
}
mat cha(const mat &a,const mat &b)
{
	mat c;
	c.a[0][0]=(a.a[0][0]*b.a[0][0]+a.a[0][1]*b.a[1][0])%mod;
	c.a[0][1]=(a.a[0][0]*b.a[0][1]+a.a[0][1]*b.a[1][1])%mod;
	c.a[1][0]=(a.a[1][0]*b.a[0][0]+a.a[1][1]*b.a[1][0])%mod;
	c.a[1][1]=(a.a[1][0]*b.a[0][1]+a.a[1][1]*b.a[1][1])%mod;
	return c;
}
mat operator +(const mat &a,const mat &b)
{
	mat c;
	c.a[0][0]=(a.a[0][0]+b.a[0][0])%mod;
	c.a[0][1]=(a.a[0][1]+b.a[0][1])%mod;
//	c.a[1][0]=(a.a[1][0]+b.a[1][0])%mod;
//	c.a[1][1]=(a.a[1][1]+b.a[1][1])%mod;
	return c;
}
struct tree
{
	struct pp
	{
		int l,r,ls,rs,sz;
		mat s;
		pp()
		{
			l=r=ls=rs=sz=0;
		}
	};
	pp a[100010];
	int n,rt;
	tree()
	{
		n=rt=0;
	}
	void build(int &p,int l,int r)
	{
		p=++n;
		a[p].l=l;
		a[p].r=r;
		if(l!=r)
		{
			int mid=(l+r)>>1;
			build(a[p].ls,l,mid);
			build(a[p].rs,mid+1,r);
		}
	}
	void change1(int p,int x,const mat &v)
	{
		if(a[p].l==a[p].r)
		{
			a[p].sz=0;
			a[p].s=v;
			return;
		}
		int mid=(a[p].l+a[p].r)>>1;
		if(x<=mid)
			change1(a[p].ls,x,v);
		else
			change1(a[p].rs,x,v);
		a[p].sz=a[a[p].ls].sz+a[a[p].rs].sz;
		a[p].s=a[a[p].ls].s+a[a[p].rs].s*f[a[a[p].ls].sz];
	}
	void change2(int p,int x,const mat &v)
	{
		if(a[p].l==a[p].r)
		{
			a[p].sz=1;
			a[p].s=v;
			return;
		}
		int mid=(a[p].l+a[p].r)>>1;
		if(x<=mid)
			change2(a[p].ls,x,v);
		else
			change2(a[p].rs,x,v);
		a[p].sz=a[a[p].ls].sz+a[a[p].rs].sz;
		a[p].s=a[a[p].ls].s+a[a[p].rs].s*f[a[a[p].ls].sz];
	}
};
tree tr;
struct p
{
	int l,r,id;
};
int size;
int cmp(p a,p b)
{
	return a.l/size!=b.l/size?a.l/size<b.l/size:a.r<b.r;
}
p b[100010];
int d[100010];
int a[100010];
int num[100010];
int m,q;
int ans[100010];
mat a1,a2,a3;
void add(int x)
{
	if(!num[x])
	{
		a3.a[0][0]=a3.a[0][1]=d[x]%mod;
		a3.a[1][0]=a3.a[1][1]=0;
		tr.change2(tr.rt,x,a3);
	}
	num[x]++;
}
void del(int x)
{
	num[x]--;
	if(!num[x])
	{
		a3.a[0][0]=a3.a[0][1]=a3.a[1][0]=a3.a[1][1]=0;
		tr.change1(tr.rt,x,a3);
	}
}
int main()
{
	scanf("%d%d",&n,&mod);
	a1.a[0][1]=a1.a[1][0]=a1.a[1][1]=1;
	a1.a[0][0]=0;
	size=sqrt(n)+0.5;
	int i;
	f[0][0][0]=f[0][1][1]=1;
	for(i=1;i<=n;i++)
		f[i]=cha(f[i-1],a1);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d[i]=a[i];
	}
	sort(d+1,d+n+1);
	m=unique(d+1,d+n+1)-d-1;
	for(i=1;i<=n;i++)
		a[i]=lower_bound(d+1,d+m+1,a[i])-d;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&b[i].l,&b[i].r);
		b[i].id=i;
	}
	sort(b+1,b+q+1,cmp);
	tr.build(tr.rt,1,m);
	memset(num,0,sizeof num);
	int l=1,r=0;
	for(i=1;i<=q;i++)
	{
		while(r<b[i].r)
			add(a[++r]);
		while(l>b[i].l)
			add(a[--l]);
		while(r>b[i].r)
			del(a[r--]);
		while(l<b[i].l)
			del(a[l++]);
		ans[b[i].id]=tr.a[1].s.a[0][0];
	}
	for(i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}