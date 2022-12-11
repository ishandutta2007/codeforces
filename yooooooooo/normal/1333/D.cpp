#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,sum=0,a[3005],cnt=0;
char s[3005];
vector<int>ans;
vector<int>stp[3000005];
void prt()
{
	for(int i=1;i<=k;i++)
	{
		printf("%d ",stp[i].size());
		for(int j=0;j<(int)stp[i].size()-1;j++)printf("%d ",stp[i][j]);
		printf("%d\n",stp[i].back());
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)if(s[i]=='R')a[++cnt]=i;
	if(cnt==0)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=cnt;i++)sum+=n-(cnt-i)-a[i];
	if(k>sum)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		ans.clear();
		for(int j=1;j<=cnt;j++)if(a[j]<n&&(j==cnt||a[j+1]>a[j]+1))ans.push_back(j);
		if(sum-ans.size()>=k-i)
		{
			for(int j=0;j<ans.size();j++)stp[i].push_back(a[ans[j]]);
			sum-=ans.size();
			for(int j=0;j<ans.size();j++)a[ans[j]]++;
			continue;
		}
		else
		{
			for(int j=0;j<sum-k+i;j++)stp[i].push_back(a[ans[j]]),a[ans[j]]++;
			for(int j=cnt;j>0;j--)
			{
				while(a[j]<n-(cnt-j))
				{
					stp[++i].push_back(a[j]);
					a[j]++;
				}
			}
			prt();
			return 0;
		}
	}
	if(sum==0)prt();
	else printf("-1\n");
	return 0;	
}