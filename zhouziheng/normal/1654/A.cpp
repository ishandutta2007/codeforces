#include<cstdio>
#include<algorithm>

using namespace std;

int a[2000];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);printf("%d\n",a[n]+a[n-1]);
	}
}