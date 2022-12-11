#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int maxint=0x7fffffff;
const int minint=0x80000000;
const ll maxll=0x7fffffffffffffffll;
const ll minll=0x8000000000000000ll;
int a[1010];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ll s=k;
	int ans=0;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		while(s*2<a[i])
		{
			s=s*2;
			ans++;
		}
		s=max(s,ll(a[i]));
	}
	printf("%d\n",ans);
	return 0;
}