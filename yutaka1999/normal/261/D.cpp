#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int in[SIZE];
int dp[SIZE];

int main()
{
	int k,n,m,t;
	scanf("%d %d %d %d",&k,&n,&m,&t);
	m=min(m,n);
	t=min(t,m);
	while(k--)
	{
		vector <int> vx;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&in[i]);
			in[i]--;
			vx.push_back(in[i]);
			dp[i]=0;
		}
		sort(vx.begin(),vx.end());
		vx.erase(unique(vx.begin(),vx.end()),vx.end());
		for(int i=0;i<n;i++) in[i]=lower_bound(vx.begin(),vx.end(),in[i])-vx.begin();
		dp[vx.size()]=0;
		int ret=1;
		for(int i=0;i<t;i++)
		{
			for(int j=n-1;j>=0;j--)
			{
				int now=in[j],vl=dp[in[j]+1]+1;
				while(now>=0&&dp[now]<vl)
				{
					dp[now--]=vl;
				}
				ret=max(ret,vl);
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}