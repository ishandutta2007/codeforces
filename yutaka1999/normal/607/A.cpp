#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#define SIZE 100005
#define BT 1024*128*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int dp[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	vector <P> vx;
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vx.push_back(P(a,b));
	}
	sort(vx.begin(),vx.end());
	int mx=0;
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		P p=vx[i];
		int pos=lower_bound(vx.begin(),vx.end(),P(p.first-p.second,-1))-vx.begin()-1;
		if(pos>=0) dp[i]=max(dp[i],dp[pos]+1);
		mx=max(mx,dp[i]);
	}
	printf("%d\n",n-mx);
	return 0;
}