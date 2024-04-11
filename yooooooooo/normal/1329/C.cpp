#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct node
{
	int x,pos;
}b[1<<22];
ll sum=0;
int T,n,m,hd,a[1<<22],dp[1<<22],vis[1<<22],x;
vector<int>ans,sr;
bool cmp(node a,node b){return a.x<b.x;}
void wrk(int x)
{
	if(!a[2*x]&&!a[2*x+1])
	{
		a[x]=0;
		return;
	}
	sr.push_back(x);
	a[x]=max(a[2*x],a[2*x+1]);
	b[a[x]].pos=x;
	if(a[2*x]>a[2*x+1])wrk(2*x);
	else wrk(2*x+1);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		sum=0;ans.clear();
		scanf("%d%d",&n,&m);
		hd=(1<<n)-1;
		for(int i=1;i<=(1<<(n+1));i++)a[i]=0;
		for(int i=1;i<(1<<n);i++)scanf("%d",&a[i]),b[i].pos=i,b[i].x=a[i],vis[i]=0,dp[i]=n,sum+=a[i];
		sort(b+1,b+(1<<n),cmp);
		for(int i=1;i<(1<<n);i++)a[b[i].pos]=i;
		for(int i=1;i<=(1<<n)-(1<<m);i++)
		{
			sr.clear();
			while(vis[hd])hd--;
			sum-=b[hd].x;
			vis[hd]=1;
			ans.push_back(b[hd].pos);
			wrk(b[hd].pos);
			for(int j=(int)sr.size()-1;j>=0;j--)
			{
				x=sr[j];
				if(!a[2*x]&&!a[2*x+1])dp[x]--;
				else
				{
					if(a[2*x]>a[2*x+1])dp[x]=dp[2*x];
					else dp[x]=dp[2*x+1];
				}
				if(dp[x]<=m)vis[a[x]]=1;
			}
		}
		printf("%lld\n",sum);
		for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
		printf("\n");
	}
}