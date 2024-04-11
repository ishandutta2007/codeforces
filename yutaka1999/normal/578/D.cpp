#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <string,P> PP;

char str[SIZE];
int dp[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",&str);
	int cnt=1;
	for(int i=0;i+1<n;i++) if(str[i]!=str[i+1]) cnt++;
	ll ret=(ll) cnt*(ll) n*(ll) (m-1);
	for(int i=n-1;i>=0;i--)
	{
		dp[i]=1;
		if(i+1<n&&str[i+1]!=str[i])
		{
			dp[i]=2;
			if(i+2<n&&str[i+2]==str[i]) dp[i]=dp[i+1]+1;
		}
		ret-=dp[i]-1;
	}
	printf("%I64d\n",ret);
	return 0;
}
/*

xyxyxyxy...
(Ak)*n*(m-1)


*/