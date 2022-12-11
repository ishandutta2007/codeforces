#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int a[5000010];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int j=(n+1)/2;
	int s=n;
	i=1;
	for(;i<=n/2&&j<=n;i++)
	{
		while(j<=n&&a[j]<a[i]*2)
			j++;
		if(j<=n)
		{
			j++;
			s--;
		}
	}
	printf("%d\n",s);
	return 0;
}