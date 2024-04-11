#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=50005,L=0,R=1;
struct node;
extern node *nil;
struct node
{
	long long v,size,size_sqr,lazy_size,sum,v1,v2;
	node *s[2],*f,*next,*rf;
	node(): v(0),size(0),size_sqr(0),lazy_size(0),sum(0),v1(0),v2(0),
			f(nil),next(nil),rf(nil) {s[L]=s[R]=nil;}
	bool root() { return f->s[L]!=this && f->s[R]!=this; }
	int get_dir() { return f->s[R]==this; }
	long long addsize(long long d)
	{
		if(this==nil)
			return 0;
		lazy_size+=d;
		size+=d;
		rf->size_sqr+=d*(size+size-d);
		long long tmp=sum;
		sum+=(v2-v1)*d;
		return 2*d*tmp;
	}
	long long changev(long long d)
	{
		node *tmp=s[R];
		push();
		for(tmp=s[R]; tmp->s[L]!=nil; tmp=tmp->s[L])
			tmp->push();
		long long delta=(d-v)*(size*size-size_sqr);
		sum+=(d-v)*(size-tmp->size);
		long long tmpv=(d-v)*(-tmp->size);
		for(tmp=s[R]; tmp!=nil; tmp=tmp->s[L])
			tmp->sum+=tmpv;
		v=d;
		update();
		return delta;
	}
	void push()
	{
		if(lazy_size)
		{
			s[L]->addsize(lazy_size);
			s[R]->addsize(lazy_size);
			lazy_size=0;
		}
	}
	void update()
	{
		sum=s[L]->sum+s[R]->sum+size*(v-rf->v);
		v2=s[R]!=nil ? s[R]->v2 : v;
		v1=s[L]!=nil ? s[L]->v1 : rf->v;
	}
	void set_f(node *d)
	{
		if(this!=nil)
			f=d;
	}
	void set_right(node *k)
	{
		push();
		node *tmp=s[R];
		for(; tmp!=nil; tmp=tmp->s[L])
			tmp->push();
		(s[R]=k)->set_f(this);
		for(tmp=s[R]; tmp->s[L]!=nil; tmp=tmp->s[L])
			;
		if(tmp!=nil)
			for(; tmp!=this; tmp=tmp->f)
				tmp->update();
		update();
	}
}u[N],*t[N]={},*nil=&u[0];
int n;
long long ans=0;
vector<int> son[N];
int dfs(int s)
{
	for(vector<int>::iterator it=son[s].begin();it!=son[s].end();++it)
	{
		long long tmp=dfs(*it);
		t[s]->size+=tmp;
		t[s]->size_sqr+=tmp*tmp;
	}
	t[s]->size+=1;
	ans+=(t[s]->size*t[s]->size - t[s]->size_sqr)*t[s]->v;
	t[s]->sum+=(t[s]->v - t[s]->rf->v) * t[s]->size;
	return t[s]->size;
}
void rotate(node *n)
{
	node *f=n->f;
	int d=n->get_dir();
	f->push();
	n->push();
	f->s[d]=n->s[!d];
	f->s[d]->set_f(f);
	if(!f->root())
		f->f->s[f->get_dir()]=n;
	n->f=f->f;
	n->s[!d]=f;
	f->f=n;
	f->update();
	n->update();
}
void Splay(node *n)
{
	while(!n->root())
		if(n->f->root())
			rotate(n);
		else
			if(n->get_dir() ^ n->f->get_dir())
				rotate(n),rotate(n);
			else
				rotate(n->f),rotate(n);
}
node* Access(node *x)
{
	node *y=nil;
	for(;x!=nil;y=x,x=x->f)
	{
		Splay(x);
		x->set_right(y);
	}
	return y;
}
void init()
{
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
		t[i]=&u[i];
	for(int i=2,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		son[x].push_back(i);
		t[i]->f=t[i]->rf=t[x];
	}
	for(int i=1;i<=n;++i)
		scanf("%I64d",&t[i]->v);
}
void set_f(int x,int y)
{
	node *p=t[x],*q=t[y],*r=p->rf;
	Splay(p);
	long long delta=p->size;
	ans+=Access(r)->addsize(-delta) + r->v*delta*delta;
	r->size_sqr-=delta*delta;
	p->rf=p->f=q;
	ans+=Access(q)->addsize(delta) + r->v*delta*delta;
	q->size_sqr+=delta*delta;
}
void work()
{
	int q,x,y;
	char ch;
	cin>>q;
	printf("%.9f\n",ans*1.0/n/n);
	for(int i=1;i<=q;++i)
	{
		cin>>ch>>x>>y;
		if(ch=='P')
		{
			node *p=Access(t[y]),*q=t[x];
			while(!q->root())
				q=q->f;
			p!=q ? set_f(x,y) : set_f(y,x);
		}
		if(ch=='V')
		{
			Access(t[x]);
			Splay(t[x]);
			ans+=t[x]->changev(y);
		}
		printf("%.9f\n",ans*1.0/n/n);
	}
}
int main()
{	
	init();
	dfs(1);
	work();
	return 0;
}