#include<iostream>
#include<cstdio>
using namespace std;
const int N=100100,L=0,R=1;
struct node;
extern node *nil;
struct node
{
	node *s[2],*f;
	int size,sum,v;
	bool rev;
	node(): f(nil),size(1),sum(0),v(0),rev(0)
	{s[L]=s[R]=nil;}
	int get_dir()
	{
		return f->s[R]==this;
	}
	void update()
	{
		size=s[L]->size+s[R]->size+1;
		sum=s[L]->sum+s[R]->sum+v;
	}
	void set_rev()
	{
		rev=!rev;
	}
	void push()
	{
		if(rev)
		{
			swap(s[L],s[R]);
			s[L]->set_rev();
			s[R]->set_rev();
			rev=false;
		}
	}
	void set_f(node *p)
	{
		if(this!=nil)
			f=p;
	}
	void set_son(node *p,int dir)
	{
		if(this!=nil)
			(s[dir]=p)->set_f(this);
	}
}u[N],*t[N]={},*nil(0);
node *const End(&u[0]);
node *&root(End->s[L]);
int n,q;
char ch[N]={};
void rotate(node *n)
{
	int d(n->get_dir());
	node *f(n->f);
	f->s[d]=n->s[!d];
	n->s[!d]->set_f(f);
	f->f->s[f->get_dir()]=n;
	n->f=f->f;
	n->s[!d]=f;
	f->f=n;
	f->update();
	n->update();
}
void Splay(node *n,node *to=root)
{
	node *f=to->f;
	while(n->f!=f)
		if(n->f->f==f)
			rotate(n);
		else
			if(n->f->get_dir()^n->f->f->get_dir())
				rotate(n),rotate(n);
			else
				rotate(n->f),rotate(n);
}
node* make_tree(int l,int r)
{
	if(l>r)
		return nil;
	int mid=(l+r)>>1;
	t[mid]->sum=t[mid]->v=1;
	t[mid]->set_son(make_tree(l,mid-1),L);
	t[mid]->set_son(make_tree(mid+1,r),R);
	t[mid]->update();
	return t[mid];
}
void init()
{
	scanf("%d %d",&n,&q);
	++n;
	for(int i=1;i<=n;++i)
		t[i]=&u[i];
	nil=&u[n+1];
	nil->size=0;
	root=make_tree(1,n);
	root->f=End;
}
node* get_kthnode(node *n,int k)
{
	for(n->push();n->s[L]->size+1!=k;n->push())
	{
		if(n->s[L]->size+1>k)
			n=n->s[L];
		else
		{
			k-=n->s[L]->size+1;
			n=n->s[R];
		}
	}
	return n;
}
node* get_segment(int l,int r)
{
	node *p=get_kthnode(root,r+1);
	Splay(p);
	p->push();
	if(l==1)
		return p->s[L];
	node *q=get_kthnode(p->s[L],l-1);
	Splay(q,p->s[L]);
	p->update();
	return q->s[R];
}
void set_rev(int l,int r)
{
	node *p=get_segment(l,r);
	p->set_rev();
	while((p=p->f)!=End)
		p->update();
}
void work()
{
	int type,l,r,p;
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d",&p);
			if(p<=(root->size)/2)
			{
				for(int last=p,now=p+1;last;--last,++now)
				{
					int delta=get_kthnode(root,last)->v;
					node *q=get_kthnode(root,now);
					q->v+=delta;
					while(q!=End)
						q->sum+=delta,q=q->f;
				}
				Splay(get_kthnode(root,p+1));
				root->set_son(nil,L);
				root->update();
			}
			else
			{
				int up=root->size;
				for(int last=p+1,now=p;last!=up;++last,--now)
				{
					int delta=get_kthnode(root,last)->v;
					node *q=get_kthnode(root,now);
					q->v+=delta;
					while(q!=End)
						q->sum+=delta,q=q->f;
				}
				Splay(get_kthnode(root,p));
				root->set_son(nil,R);
				root->set_son(t[n],R);
				t[n]->s[L]=t[n]->s[R]=nil;
				t[n]->update();
				root->update();
				set_rev(1,root->size-1);
			}
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",get_segment(l+1,r)->sum);
		}
	}
}
int main()
{	
	init();
	work();
	return 0;
}