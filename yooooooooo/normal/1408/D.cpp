#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
	node(int nx=0,int ny=0){x=nx;y=ny;}
}st[4000005];
int n,m,a[2005],b[2005],c[2005],d[2005],ans,cnt=0,mx[4000005];
bool cmp(node a,node b){return a.x<b.x;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&c[i],&d[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)st[++cnt]=node(c[j]-a[i]+1,d[j]-b[i]+1);
	sort(st+1,st+cnt+1,cmp);
	//for(int i=1;i<=cnt;i++)printf("#%d %d\n",st[i].x,st[i].y);
	mx[cnt+1]=0;
	for(int i=cnt;i;i--)mx[i]=max(mx[i+1],st[i].y);
	ans=mx[1];
	for(int i=1;i<=cnt;i++)ans=min(ans,max(st[i].x,0)+mx[i+1]);
	printf("%d\n",ans);
	return 0;
}