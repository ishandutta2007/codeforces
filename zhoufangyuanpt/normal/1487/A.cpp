#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ss=0;
		for(int i=1;i<=n;i++)ss+=a[i]!=a[1];
		printf("%d\n",ss);
	}
	return 0;
}