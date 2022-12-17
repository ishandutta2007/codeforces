#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define iter set<node>::iterator 
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?x:-x;
}
struct node
{
	int l,r;
	mutable int v;
	node(int ll,int rr=-1,int vv=0){l=ll,r=rr,v=vv;}
	inline bool operator<(const node&rhs)const
	{
		return l<rhs.l;
	}
};
set<node>s;
int n,m,sum;
inline iter split(int pos)
{
	iter it=s.lower_bound(node(pos));
	if(it!=s.end()&&it->l==pos)return it;
	--it;
	int l=it->l,r=it->r,val=it->v;
	s.erase(it);
	s.insert(node(l,pos-1,val));
	return s.insert(node(pos,r,val)).first; 
}
inline void assign(int l,int r,int val)
{
	iter ri=split(r+1),le=split(l);
	for(iter it=le;it!=ri;++it)
	{
		if(it->v==1)sum-=(it->r-it->l+1);
	}
	s.erase(le,ri);
	s.insert(node(l,r,val));
	if(val==1)sum+=r-l+1;
}
int main()
{
	n=getint(),m=getint();
	sum=n;
	s.insert(node(1,n,1));
	for(int i=1;i<=m;++i)
	{
		int x=getint(),y=getint(),opt=getint();
		if(opt==1)assign(x,y,0);
		else assign(x,y,1);
		printf("%d\n",sum);
	}
	return 0;
}