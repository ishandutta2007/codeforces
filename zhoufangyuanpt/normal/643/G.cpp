#pragma GCC optimize("O2")
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct val{int id,cnt;};
inline bool cmp(val x,val y){return x.cnt>y.cnt;}
struct node
{
	int l,r,lc,rc;
	vector<val> c;
	int bk;
}tr[310000];int len;
int b[160000];
inline vector<val> operator+(vector<val> x,vector<val> y)
{
	vector<val> z;
	for(val key:x)
	{
		if(b[key.id]==-1)
		{
			b[key.id]=z.size();
			z.push_back({key.id,key.cnt});
		}
		else z[b[key.id]].cnt+=key.cnt;
	}
	for(val key:y)
	{
		if(b[key.id]==-1)
		{
			b[key.id]=z.size();
			z.push_back({key.id,key.cnt});
		}
		else z[b[key.id]].cnt+=key.cnt;
	}
	for(val key:z)b[key.id]=-1;
	sort(z.begin(),z.end(),cmp);
	while(z.size()>7)z.pop_back();
	return z;
}
int a[160000];
void bt(int l,int r)
{
	len++;int now=len;
	tr[now].l=l;tr[now].r=r;tr[now].lc=tr[now].rc=-1;tr[now].bk=0;
	if(l<r)
	{
		int mid=(l+r)/2;
		tr[now].lc=len+1;bt(l,mid);
		tr[now].rc=len+1;bt(mid+1,r);
		tr[now].c=tr[tr[now].lc].c+tr[tr[now].rc].c;
	}
	else tr[now].c.push_back({a[l],1});
}
inline void pushdown(int x)
{
	if(tr[x].bk!=0)
	{
		int lc=tr[x].lc,rc=tr[x].rc;
		tr[lc].c.clear();
		tr[lc].c.push_back({tr[x].bk,tr[lc].r-tr[lc].l+1});
		tr[rc].c.clear();
		tr[rc].c.push_back({tr[x].bk,tr[rc].r-tr[rc].l+1});
		tr[lc].bk=tr[x].bk;
		tr[rc].bk=tr[x].bk;
		tr[x].bk=0;
	}
}
void change(int now,int l,int r,int id)
{
	if(tr[now].l==l&&tr[now].r==r)
	{
		tr[now].c.clear();
		tr[now].c.push_back({id,tr[now].r-tr[now].l+1});
		tr[now].bk=id;
		return ;
	}
	pushdown(now);
	int lc=tr[now].lc,rc=tr[now].rc;
	int mid=(tr[now].l+tr[now].r)/2;
	if(r<=mid)change(lc,l,r,id);
	else if(l>=mid+1)change(rc,l,r,id);
	else change(lc,l,mid,id),change(rc,mid+1,r,id);
	tr[now].c=tr[lc].c+tr[rc].c;
}
vector<val> Ans(int now,int l,int r)
{
	if(tr[now].l==l&&tr[now].r==r)return tr[now].c;
	pushdown(now);
	int lc=tr[now].lc,rc=tr[now].rc;
	int mid=(tr[now].l+tr[now].r)/2;
	if(r<=mid)return Ans(lc,l,r);
	else if(l>=mid+1)return Ans(rc,l,r);
	else return Ans(lc,l,mid)+Ans(rc,mid+1,r);
}
int main()
{
	int n,m,p;scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(b,-1,sizeof(b));
	len=0;bt(1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,l,r;scanf("%d%d%d",&opt,&l,&r);
		if(opt==1)
		{
			int id;scanf("%d",&id);
			change(1,l,r,id);
		}
		else
		{
			vector<val> cc=Ans(1,l,r);
			if(cc.size()<=100/p)
			{
				printf("%d",cc.size());
				for(val key:cc)printf(" %d",key.id);
				printf("\n");
			}
			else
			{
				printf("%d",100/p);
				for(int i=0;i<100/p;i++)printf(" %d",cc[i].id);
				printf("\n");
			}
		}
	}
	return 0;
}