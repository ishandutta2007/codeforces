#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#define INF 1500000005

using namespace std;

struct T
{
	T *l,*r;
	int val;
	int add;
	int sz;
	
	T(int val=0,int add=0,int sz=1,T *l=NULL,T *r=NULL):val(val),add(add),sz(sz),l(l),r(r){}
	
	void pass()
	{
		if(l)
		{
			l->val+=add;
			l->add+=add;
		}
		if(r)
		{
			r->val+=add;
			r->add+=add;
		}
		add=0;
	}
	void update()
	{
		sz=1;
		if(l) sz+=l->sz;
		if(r) sz+=r->sz;
	}
};
typedef pair <T*,T*> PT;
T *merge(T *l,T *r)
{
	if(l==NULL) return r;
	if(r==NULL) return l;
	if(rand()%(l->sz+r->sz)<l->sz)
	{
		l->pass();
		l->r=merge(l->r,r);
		l->update();
		return l;
	}
	else
	{
		r->pass();
		r->l=merge(l,r->l);
		r->update();
		return r;
	}
}
PT split(T *v,int low)//low
{
	if(v==NULL) return PT(NULL,NULL);
	v->pass();
	if(v->val<low)
	{
		PT p=split(v->r,low);
		v->r=p.first;
		v->update();
		return PT(v,p.second);
	}
	else
	{
		PT p=split(v->l,low);
		v->l=p.second;
		v->update();
		return PT(p.first,v);
	}
}
T *insert(T *v,int x)
{
	PT p=split(v,x);
	T *now=new T(x);
	return merge(p.first,merge(now,p.second));
}
int gs(T *v)
{
	if(v==NULL) return 0;
	return v->sz;
}
T *erase(T *v,int x)
{
	PT p=split(v,x);
	PT q=split(p.second,x+1);
	//assert(gs(q.first)==1);
	//printf("%d : %d %d : %d %d\n",x,gs(p.first),gs(p.second),gs(q.first),gs(q.second));
	return merge(p.first,q.second);
}
T *root;
void ins(int x){root=insert(root,x);}
void erase(int x){root=erase(root,x);}
int lower_B(int x)
{
	T *at=root;
	int ret=INF;
	while(at)
	{
		at->pass();
		if(at->val>=x)
		{
			ret=at->val;
			at=at->l;
		}
		else
		{
			at=at->r;
		}
	}
	return ret;
}
void add(int r,int v)//[0,r]+v
{
	PT p=split(root,r+1);
	if(p.first)
	{
		p.first->add+=v;
		p.first->val+=v;
	}
	root=merge(p.first,p.second);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int gt=lower_B(r);
		if(gt!=INF) erase(gt);
		add(r-1,1);
		add(l,-1);
		ins(l);
		/*
		vector <int> V;
		int bef=-INF;
		while(1)
		{
			int mn=lower_B(bef);
			if(mn==INF) break;
			printf("%d ",mn);
			bef=mn+1;
		}puts("");*/
	}
	int ret=0;
	if(root) ret=root->sz;
	printf("%d\n",ret);
	return 0;
}