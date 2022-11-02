#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
const int M=50500;
struct rectangle
{
	int x1,y1,x2,y2;
}r[M]={};
struct event
{
	int pos,y1,y2,type;
}e[M<<1]={};
bool event_cmp(const event &e1,const event &e2)
{
	return e1.pos<e2.pos;
}
struct node
{
	int l,r,sum,lazy,mid;
}t[M<<3]={};
int n,m,k,v[M<<1]={};
#define L (k<<1)
#define R ((k<<1)|1)
inline void update(int k)
{
	if(t[k].lazy)
		t[k].sum=v[t[k].r]-v[t[k].l]+1;
	else
	{
		if(t[k].l==t[k].r)
			t[k].sum=0; 
		else
		{
			t[k].sum=t[L].sum+t[R].sum;
			if(t[k].mid)
				t[k].sum+=v[t[R].l]-v[t[L].r]-1;
		}
	}
}
void make_tree(int l,int r,int k)
{
	if(l!=r)
	{
		int mid=(l+r)>>1;
		make_tree(l,mid,L);
		make_tree(mid+1,r,R);
	}
	t[k].l=l;
	t[k].r=r;
}
void change(int l,int r,int c,int k)
{
	if(t[k].l>=l && t[k].r<=r)
	{
		t[k].lazy+=c;
		update(k);
		return;
	}
	if(t[L].r>=l && t[R].l<=r)
		t[k].mid+=c;
	if(t[L].r>=l)
		change(l,r,c,L);
	if(t[R].l<=r)
		change(l,r,c,R);
	update(k);
}
#undef L
#undef R
void init()
{
	n=getint(),m=getint(),k=getint();
	for(int i=1;i<=m;++i)
	{
		r[i].x1=getint();
		r[i].y1=getint();
		r[i].x2=getint();
		r[i].y2=getint();
	}
	make_tree(1,m+m,1);
}
void make_event()
{
	for(int i=1,tot=0;i<=m;++i)
	{
		e[++tot]={r[i].x1,r[i].y1,r[i].y2,1};
		e[++tot]={r[i].x2+1,r[i].y1,r[i].y2,-1};
		v[tot-1]=r[i].y1;
		v[tot]=r[i].y2;
	}
	sort(v+1,v+m+m+1);
	sort(e+1,e+m+m+1,event_cmp);
	for(int i=1;i<=m+m;++i)
	{
		e[i].y1=lower_bound(v+1,v+m+m+1,e[i].y1)-v;
		e[i].y2=lower_bound(v+1,v+m+m+1,e[i].y2)-v;
	}
}
int calc()
{
	int ans=0;
	for(int i=1;i<=m+m;++i)
	{
		if(e[i].pos!=e[i-1].pos)
			ans+=(t[1].sum&1)*(e[i].pos-e[i-1].pos);
		change(e[i].y1,e[i].y2,e[i].type,1);
	}
	return ans&1;
}
void change()
{
	for(int i=1;i<=m;++i)
	{
		r[i].x1=(r[i].x1+1)>>1;
		r[i].y1=(r[i].y1+1)>>1;
		r[i].x2=r[i].x2>>1;
		r[i].y2=r[i].y2>>1;
	}
}
void work()
{
	int ans=0;
	for(int i=1;i<=k;i<<=1)
	{
		make_event();
		ans^=((i>>1)^i)*calc();
		change();
		if(ans&(i-1))
			break;
	}
	if(ans)
		puts("Hamed");
	else
		puts("Malek");
}
int main()
{	
	init();
	work();
	return 0;
}