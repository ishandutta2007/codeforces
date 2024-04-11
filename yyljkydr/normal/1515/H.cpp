#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,M=20,V=(1<<M)-1;

int n,q,a[N];

int rt;

int tot;

struct T{
	int ls,rs,d;
	int h[2];
	int tag;
	int sum;
}t[N*M*2];

void update(int x)
{
	if(t[x].d==-1)
		return;
	t[x].h[0]=t[t[x].ls].h[0]|t[t[x].rs].h[0];
	t[x].h[1]=t[t[x].ls].h[1]|t[t[x].rs].h[1];
	t[x].sum=t[t[x].ls].sum+t[t[x].rs].sum;
}

void add(int x,int v)
{
	if(!x)
		return;
	if(t[x].d!=-1&&(v&(1<<t[x].d)))
		swap(t[x].ls,t[x].rs);
	t[x].tag^=v;
	int h0=t[x].h[0],h1=t[x].h[1];
	t[x].h[0]=(h0^(h0&v))|(h1&v);
	t[x].h[1]=(h1^(h1&v))|(h0&v);
}

void pushdown(int x)
{
	if(t[x].tag)
	{
		add(t[x].ls,t[x].tag);
		add(t[x].rs,t[x].tag);
		t[x].tag=0;
	}
}

void insert(int &x,int v,int d) 
{
	if(!x)
		x=++tot;
	t[x].d=d;
	if(d==-1)
	{
		t[x].h[1]=v;
		t[x].h[0]=v^V;
		t[x].sum=1;
		return;
	}
	if(v&(1<<d))
		insert(t[x].rs,v,d-1);
	else
		insert(t[x].ls,v,d-1);
	update(x);
}

void merge(int &x,int y)//merging Tree y into Tree x
{
	if(!x||!y)
	{
		x=x^y;
		return;
	}
	pushdown(x);
	pushdown(y);
	// t[x].sum+=t[y].sum;
	merge(t[x].ls,t[y].ls);
	merge(t[x].rs,t[y].rs);
	update(x);
}

void split(int &x,int &y,int l,int r,int a,int b)//spliting range [l,r] from Tree x and make Tree y
{
	if(!x)
	{
		y=0;
		return;
	}
	if(l<=a&&b<=r)
	{
		y=x;
		x=0;
		return;
	}
	assert(!y);
	y=++tot;
	t[y].d=t[x].d;
	pushdown(x);
	int mid=(a+b)>>1;
	if(l<=mid)
		split(t[x].ls,t[y].ls,l,r,a,mid);
	if(r>mid)
		split(t[x].rs,t[y].rs,l,r,mid+1,b);
	update(x);
	update(y);
}

void change(int x,int v)
{
	if(!x)
		return;
	if(!(v&t[x].h[0]&t[x].h[1]))
	{
		add(x,v&t[x].h[0]);
		return;
	}
	assert(t[x].d!=-1);
	pushdown(x);
	if(v&(1<<t[x].d))
		add(t[x].ls,1<<t[x].d),merge(t[x].rs,t[x].ls),t[x].ls=0;
	change(t[x].ls,v);
	change(t[x].rs,v);
	update(x);
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),insert(rt,a[i],M-1);
	while(q--)
	{
		int op,l,r,x;
		scanf("%d%d%d",&op,&l,&r);
		int nt=0;
		split(rt,nt,l,r,0,V);
		// printf("%d\n",t[rt].sum);
		if(op==1)
		{
			scanf("%d",&x);
			add(nt,V);
			change(nt,x^V);
			add(nt,V);
		}
		if(op==2)
		{
			scanf("%d",&x);
			change(nt,x);
		}
		if(op==3)
		{
			scanf("%d",&x);
			add(nt,x);	
		}
		if(op==4)
			printf("%d\n",t[nt].sum);
		merge(rt,nt);
	}
}