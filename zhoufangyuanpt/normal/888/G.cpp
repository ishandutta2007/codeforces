#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int son[2],size,l,r;
}tr[6010000];int len;
inline void bt(int x,int p)
{
	int now=0;
	for(int i=29;i>=0;i--)
	{
		int c=(x&(1<<i))>>i;
		if(tr[now].son[c]==0)tr[now].son[c]=++len;
		now=tr[now].son[c];
		tr[now].size++;
		if(tr[now].l==0)tr[now].l=p;
		if(p>tr[now].r)tr[now].r=p;
	}
}
int find(int now,int x,int dep)
{
	if(dep==0)return 0;
	int c=(x&dep)/dep;
	if(tr[now].son[c]!=0)return find(tr[now].son[c],x,dep/2);
	return dep+find(tr[now].son[c^1],x,dep/2);
}
int a[210000];
long long dfs(int now,int dep)
{
	if(now==0&&dep!=1<<29)return 0;
	int ss=0;
	if(tr[now].son[0]!=0&&tr[now].son[1]!=0)
	{
		int x,y;
		if(tr[tr[now].son[0]].size<tr[tr[now].son[1]].size)x=tr[now].son[0],y=tr[now].son[1];
		else x=tr[now].son[1],y=tr[now].son[0];
		ss=1<<30;
		for(int i=tr[x].l;i<=tr[x].r;i++)
		{
			int s=find(y,a[i],dep/2);
			if(s+dep<ss)ss=s+dep;
		}
	}
	return ss+dfs(tr[now].son[0],dep/2)+dfs(tr[now].son[1],dep/2);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	len=0;memset(tr,0,sizeof(tr));
	for(int i=1;i<=n;i++)bt(a[i],i);
	printf("%lld\n",dfs(0,1<<29));
	return 0;
}