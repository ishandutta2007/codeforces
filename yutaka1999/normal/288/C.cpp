#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long int ll;

ll tag[2000005];

void solve(int n)
{
	if(n<=0) return;
	int s;
	for(s=1;s<=n;s*=2);
	for(int i=s/2;i<=n;i++)
	{
		tag[i]=s-i-1;
		tag[s-i-1]=i;
	}
	solve(s-n-2);
}

int main()
{
	int n;
	scanf("%d",&n);
	memset(tag,0,sizeof(tag));
	solve(n);
	ll ret=0;
	for(int i=0;i<=n;i++) ret+=i^tag[i];
	printf("%I64d\n",ret);
	for(int i=0;i<=n;i++)
	{
		if(i!=0) printf(" ");
		printf("%I64d",tag[i]);
	}printf("\n");
	return 0;
}