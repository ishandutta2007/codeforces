#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int root;
struct node
{
	int l,r,c,size;
	long long key,a1,d;
}tr[110000];int len;
inline void update(int x){tr[x].size=tr[tr[x].l].size+tr[tr[x].r].size+1;}
inline void pushdown(int x)
{
	tr[tr[x].l].key+=tr[x].a1+tr[tr[tr[x].l].l].size*tr[x].d;
	tr[tr[x].l].a1+=tr[x].a1;tr[tr[x].l].d+=tr[x].d;
	tr[tr[x].r].key+=tr[x].a1+(tr[tr[x].l].size+1+tr[tr[tr[x].r].l].size)*tr[x].d;
	tr[tr[x].r].a1+=tr[x].a1+(tr[tr[x].l].size+1)*tr[x].d;tr[tr[x].r].d+=tr[x].d;
	tr[x].a1=tr[x].d=0;
}
void split(int now,int k,int &x,int &y)
{
	if(now==0)x=y=0;
	else
	{
		pushdown(now);
		if(k<=tr[tr[now].l].size)
		{
			y=now;split(tr[now].l,k,x,tr[y].l);
		}
		else
		{
			x=now;split(tr[now].r,k-tr[tr[now].l].size-1,tr[x].r,y);
		}
		update(now);
	}
}
int merge(int x,int y)
{
	if(x==0||y==0)return x+y;
	if(tr[x].c<tr[y].c)
	{
		pushdown(x);
		tr[x].r=merge(tr[x].r,y);
		update(x);
		return x;
	}
	else
	{
		pushdown(y);
		tr[y].l=merge(x,tr[y].l);
		update(y);
		return y;
	}
}
inline int new_node(long long key)
{
	len++;
	tr[len].l=tr[len].r=0;tr[len].c=rand();tr[len].size=1;
	tr[len].key=key;tr[len].a1=tr[len].d=0;
	return len;
}
long long select(int x,int k)
{
	if(x==0)return 0;
	if(k==tr[tr[x].l].size+1)return tr[x].key;
	else
	{
		pushdown(x);
		if(k<=tr[tr[x].l].size)return select(tr[x].l,k);
		else return select(tr[x].r,k-tr[tr[x].l].size-1);
	}
}
inline long long mymax(long long x,long long y){return x>y?x:y;}
long long Ans(int x)
{
	if(x==0)return 0;pushdown(x);
	return mymax(tr[x].key,mymax(Ans(tr[x].l),Ans(tr[x].r)));
}
int main()
{
	int n;scanf("%d",&n);root=len=0;
	for(int i=1;i<=n;i++)
	{
		long long x;scanf("%lld",&x);
		int l=0,r=tr[root].size;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(select(root,mid)+(mid+1)*x<=select(root,mid+1))l=mid+1;
			else r=mid;
		}
		long long key=select(root,r);
		int a,b;split(root,r,a,b);
		b=merge(new_node(key),b);
		tr[b].key+=(r+1)*x+tr[tr[b].l].size*x;
		tr[b].a1+=(r+1)*x;
		tr[b].d+=x;
		root=merge(a,b);
	}
	printf("%lld\n",Ans(root));
	return 0;
}