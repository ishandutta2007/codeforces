#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 4005
#define MX 40005

using namespace std;
typedef long long int ll;

int sum[SIZE];
int cnt[MX];
char str[SIZE];

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",&str);
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		sum[i]=str[i]-'0';
		if(i>0) sum[i]+=sum[i-1];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int val=sum[j]-(i==0?0:sum[i-1]);
			cnt[val]++;
		}
	}
	ll ret=0;
	for(int i=0;i<MX;i++)
	{
		if(i==0)
		{
			if(a==0)
			{
				int num=n*(n+1)/2;
				ret+=(ll) num*(ll) cnt[i];
			}
		}
		else if(a%i==0&&a/i<MX)
		{
			ret+=(ll) cnt[i]*(ll) cnt[a/i];
		}
	}
	printf("%I64d\n",ret);
	return 0;
}