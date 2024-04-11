#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,i,a[2000002];
long long cnt=0;
int main()
{
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	scanf("%d",&a[i]);
	cnt+=a[i];
}
if(n==1||(n==2&&a[1]==a[2]))printf("-1");
else
{
	if(a[1]*2==cnt)printf("2\n1 2");
	else printf("1\n1");
}
return 0;
}