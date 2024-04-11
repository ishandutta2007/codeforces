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
pii a[100010];
int c[100010];
int cmp(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i].first);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i].second);
	for(i=1;i<=n;i++)
		c[i]=i;
	sort(c+1,c+n+1,cmp);
	printf("%d\n",n/2+1);
	printf("%d ",c[1]);
	for(i=2;i+1<=n;i+=2)
		if(a[c[i]].second>a[c[i+1]].second)
			printf("%d ",c[i]);
		else
			printf("%d ",c[i+1]);
	if(!(n&1))
		printf("%d ",c[n]);
	return 0;
}