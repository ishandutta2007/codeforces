#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100005],q[100005],b[100005];
int next[200005],last[100005],to[200005];
int x,y,i,j,k,l,s,m,n,ans,tot;
int da[100005];
int fa[100005],f[100005];
inline void add(int o,int p)
{
	next[++tot]=last[o];
	last[o]=tot;
	to[tot]=p;
}
inline void build()
{
	int l=0,r=1;
	q[1]=1;
	while (l<r)
	{
		int k=q[++l];
		for (int i=last[k];i;i=next[i])
		{
			if (fa[k]!=to[i])
			{
				fa[to[i]]=k;
				q[++r]=to[i];
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	build();
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	scanf("%d",&b[i]);
	for (i=1;i<=n;i++)
	{
		int k=q[i];
		int s=f[fa[fa[k]]];
		if (a[k]^(s%2)!=b[k])
		{
			ans++;
			da[ans]=k;
			f[k]++;
		}
		f[k]+=s;
	}
	printf("%d\n",ans);
	sort(da+1,da+1+ans);
	for (i=1;i<=ans;i++)
	printf("%d\n",da[i]);
}