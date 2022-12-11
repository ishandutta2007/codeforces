#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
	int x,id;
	node(int nx=0,int nid=0){x=nx;id=nid;}
}a[300005];
int T,n,m=0,u,v,N[3],cnt=0,pre[3][300005],suf[3][300005],x,y;
ll ans=0;
const ll inf=4e18;
bool cmp(node a,node b){return a.x<b.x;}
void solve(int id)
{
	int x,n;
	n=N[id];
	m+=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[++cnt]=node(x,id);
	}
}
ll prod(ll x,ll y,ll z){return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		m=0;cnt=0;
		ans=inf;
		scanf("%d%d%d",&N[0],&N[1],&N[2]);
		pre[0][0]=pre[1][0]=pre[2][0]=0;
		solve(0);solve(1);solve(2);
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			pre[0][i]=pre[0][i-1];
			pre[1][i]=pre[1][i-1];
			pre[2][i]=pre[2][i-1];
			pre[a[i].id][i]=a[i].x;
		}
		suf[0][m+1]=suf[1][m+1]=suf[2][m+1]=0;
		for(int i=m;i>0;i--)
		{
			suf[0][i]=suf[0][i+1];
			suf[1][i]=suf[1][i+1];
			suf[2][i]=suf[2][i+1];
			suf[a[i].id][i]=a[i].x;
		}
		for(int i=1;i<=m;i++)
		{
			u=(a[i].id+1)%3;v=(a[i].id+2)%3;
			if(pre[u][i]&&suf[v][i])ans=min(ans,prod(pre[u][i],suf[v][i],a[i].x));
			swap(u,v);
			if(pre[u][i]&&suf[v][i])ans=min(ans,prod(pre[u][i],suf[v][i],a[i].x));
		}
		printf("%lld\n",ans);
	}
	return 0;
}