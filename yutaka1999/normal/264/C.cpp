#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define INF 10000000000000000LL

using namespace std;
typedef long long int ll;

int c[SIZE];
int v[SIZE];
ll dp[SIZE];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		c[i]--;
	}
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		fill(dp,dp+n,-INF);
		ll m1=0,m2=0;
		for(int j=0;j<n;j++)
		{
			ll vl=max(dp[c[j]]+(ll) a*(ll) v[j],(m1==dp[c[j]]?m2:m1)+(ll) b*(ll) v[j]);
			if(dp[c[j]]<vl)
			{
				if(m1==dp[c[j]]) m1=vl;
				else
				{
					ll vx=vl;
					if(vl>m1) swap(m1,vx);
					if(vl>m2) swap(m2,vx);
				}
				dp[c[j]]=vl;
			}
		}
		printf("%I64d\n",m1);
	}
	return 0;
}