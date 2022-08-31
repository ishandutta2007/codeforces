#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctime>
#define MOD 1000000007
#define MM 1000000009
#define SZ 3
#define SIZE 100005

using namespace std;
typedef long long int ll;

char str[SIZE];
ll shash[SIZE][SZ],md[SZ];
ll B[SZ],BB[SZ];
bool ok[SIZE];
int dp[SIZE],rdp[SIZE];

int main()
{
	srand((unsigned) time(NULL));
	scanf("%s",&str);
	int n=strlen(str);
	for(int i=0;i<SZ;i++) B[i]=rand()%(MM-1)+1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<SZ;j++)
		{
			shash[i][j]=str[i]-'a'+1;
			if(i>0)
			{
				shash[i][j]+=shash[i-1][j]*B[j]%MM;
				if(shash[i][j]>=MM) shash[i][j]-=MM;
			}
		}
	}
	scanf("%s",&str);
	int m=strlen(str);
	memset(md,0,sizeof(md));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<SZ;j++)
		{
			md[j]*=B[j];
			md[j]%=MM;
			md[j]+=str[i]-'a'+1;
			if(md[j]>=MM) md[j]-=MM;
		}
	}
	for(int i=0;i<SZ;i++)
	{
		BB[i]=1;
		for(int j=0;j<m;j++)
		{
			BB[i]*=B[i];
			BB[i]%=MM;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i+m<=n)
		{
			bool o=true;
			for(int j=0;j<SZ;j++)
			{
				ll d=shash[i+m-1][j]-(i==0?0:shash[i-1][j]*BB[j]%MM);
				if(d<0) d+=MM;
				if(d!=md[j])
				{
					o=false;
					break;
				}
			}
			ok[i]=o;
		}
	}
	memset(dp,0,sizeof(dp));
	memset(rdp,0,sizeof(rdp));
	dp[n]=rdp[n]=1;
	int sum=0;
	for(int i=n-1;i>=0;i--)
	{
		if(ok[i])
		{
			sum=rdp[i+m];
		}
		dp[i]=dp[i+1]+sum;
		if(dp[i]>=MOD) dp[i]-=MOD;
		rdp[i]=rdp[i+1]+dp[i];
		if(rdp[i]>=MOD) rdp[i]-=MOD;
		//printf("%d %d\n",dp[i],rdp[i]);
	}
	printf("%d\n",(dp[0]-1+MOD)%MOD);
	return 0;
}