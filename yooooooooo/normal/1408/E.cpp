#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
	int x,y,w;
	node(int nx=0,int ny=0,int nw=0){x=nx;y=ny;w=nw;}
}st[200005];
int m,n,k,a[100005],b[100005],dsu[200005],cnt=0,x,fx,fy;
ll ans=0;
int getf(int x){return dsu[x]==x?x:dsu[x]=getf(dsu[x]);}
bool cmp(node a,node b){return a.w>b.w;}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n+m;i++)dsu[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			st[++cnt]=node(i,m+x,a[i]+b[x]);
			ans+=(ll)(a[i]+b[x]);
		}
	}
	sort(st+1,st+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		fx=getf(st[i].x);
		fy=getf(st[i].y);
		if(fx==fy)continue;
		ans-=(ll)st[i].w;
		dsu[fx]=fy;
	}
	printf("%lld\n",ans);
	return 0;
}