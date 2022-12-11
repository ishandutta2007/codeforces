#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,k,a[200005],b[200005],pos[200005],vis[200005],ans=1,inv;
const int mod=998244353;
bool solve(int l,int r,int p)
{
	if(l>r)return false;
	if(min(vis[l],vis[r])<p)return true;
	if(vis[l]<vis[r])return solve(l+1,r,vis[l]);
	else return solve(l,r-1,vis[r]);
}
int main()
{
	inv=(mod+1)/2;
	scanf("%d",&T);
	while(T--)
	{
		ans=1;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			vis[i]=0;
			pos[a[i]]=i;
		}
		for(int i=1;i<=k;i++)scanf("%d",&b[i]),vis[pos[b[i]]]=i;
		for(int i=1;i<=n;)
		{
			if(vis[i]==0)
			{
				i++;
				continue;
			}
			int hd=i;
			while(i<=n&&vis[i])i++;
			if(solve(hd,i-1,0))ans=0;
			ans=2ll*ans%mod;
			//printf("%d %d %d\n",ans,i,hd);
		}
		//printf("%d\n",ans);
		if(vis[1])
		{
			for(int i=2;i<=n&&vis[i];i++)if(vis[i]>vis[i-1])ans=0;
			ans=1ll*ans*inv%mod;
		}
		if(vis[n])
		{
			for(int i=n-1;i&&vis[i];i--)if(vis[i]>vis[i+1])ans=0;
			ans=1ll*ans*inv%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}