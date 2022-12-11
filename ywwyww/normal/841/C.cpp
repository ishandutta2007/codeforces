#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii a[200010];
pii b[200010];
int ans[200010];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i].first);
		b[i].second=i;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,greater<pii>());
	for(i=1;i<=n;i++)
		ans[b[i].second]=a[i].first;
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}