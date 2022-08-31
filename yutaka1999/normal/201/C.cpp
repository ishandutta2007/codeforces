#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;

ll in[SIZE];
ll dp[SIZE];
ll cnt[SIZE];
int n;

ll solve()
{
	ll ret=0;
	memset(dp,0,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
	for(int i=n-1;i>=0;i--)
	{
		if(i==0||in[i]==1)
		{
			int r=i+1;
			while(r<n&&in[r]!=1) r++;
			ll sum=0;
			for(int j=r-1;j>=i;j--)
			{
				sum+=in[j]-(in[j]%2==0?1:0);
				dp[j]=sum+dp[r];
				cnt[j]=sum;
			}
			ll mx=0,bk=0;
			for(int j=r-1;j>=i;j--)
			{
				if(in[j]%2==0) bk++;
				else bk--;
				mx=max(mx,bk);
				dp[j]=max(dp[j],cnt[j]+mx);
			}
			ll sum2=0;
			for(int j=i;j<=r;j++)
			{
				ret=max(ret,sum2+dp[j]);
				sum2+=2*(in[j]/2);
			}
		}
	}
	return ret;
}
int main()
{
	scanf("%d",&n);n--;
	for(int i=0;i<n;i++) scanf("%I64d",&in[i]);
	ll ret=solve();
	for(int l=0,r=n-1;l<r;l++,r--) swap(in[l],in[r]);
	ret=max(ret,solve());
	printf("%I64d\n",ret);
	return 0;
}