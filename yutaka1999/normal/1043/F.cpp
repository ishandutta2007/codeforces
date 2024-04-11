#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cassert>
#define SIZE 300005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

bool dp[SIZE];
bool gen[SIZE];
ll cnt[SIZE];

int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	int n;
	scanf("%d",&n);
	int g=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		gen[a]=true;
		g=gcd(g,a);
	}
	if(g!=1)
	{
		puts("-1");
		return 0;
	}
	dp[0]=true;
	int ans=0;
	while(1)
	{
		ans++;
		for(int i=SIZE-1;i>=1;i--)
		{
			cnt[i]=0;
			ll a=0,b=0,sum=0;
			for(int j=0;j<SIZE;j+=i)
			{
				a+=dp[j];
				b+=gen[j];
				sum+=cnt[j];
			}
			cnt[i]=a*b-sum;
		}
		for(int i=1;i<SIZE;i++) dp[i]|=(cnt[i]>0);
		if(dp[1])
		{
			printf("%d\n",ans);
			break;
		}
	}
	return 0;
}