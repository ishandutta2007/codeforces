#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char ans[1000005];

int main()
{
	memset(ans,0,sizeof(ans));
	int n,k;
	scanf("%d %d",&n,&k);
	if(n==1&&k==1)
	{
		printf("a\n");
		return 0;
	}
	if(n<k||k==1)
	{
		printf("%d\n",-1);
		return 0;
	}
	for(int i=0;i<n-k+2;i++)
	{
		if(i%2==0) ans[i]='a';
		else ans[i]='b';
	}
	for(int i=n-k+2;i<n;i++) ans[i]='a'+(i-(n-k));
	printf("%s\n",ans);
	return 0;
}