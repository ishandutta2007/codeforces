#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#define SIZE 100005
#define MX 11

using namespace std;
typedef long long int ll;

char str[SIZE];
ll dp[MX],nxt[MX];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	memset(dp,0,sizeof(dp));
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		int c=str[i]-'0';
		memset(nxt,0,sizeof(nxt));
		for(int j=c+1;j<MX;j++)
		{
			int to=(j*j-j-2)/2+c;
			if(to<0) to+=MX;
			to%=MX;
			nxt[to]+=dp[j];
		}
		if(c>0) nxt[c]++;
		for(int j=0;j<MX;j++)
		{
			ret+=nxt[j];
			dp[j]=nxt[j];
		}
	}
	printf("%lld\n",ret);
	return 0;
}