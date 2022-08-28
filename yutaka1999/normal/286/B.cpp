#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 3000005

using namespace std;

int ans[3000005];

int main()
{
	memset(ans,-1,sizeof(ans));
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) ans[i]=i+1;
	int s=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=((n-1)/i)*i;j>=0;j-=i)
		{
			if(j+i>n) ans[s+n]=ans[j+s];
			else ans[j+i+s]=ans[j+s];
		}s++;
	}
	for(int i=s;i<s+n;i++)
	{
		if(i!=s) printf(" ");
		printf("%d",ans[i]);
	}printf("\n");
	return 0;
}