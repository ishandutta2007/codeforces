#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int a[100010];
int main()
{
	int n;
	ll k;
	scanf("%d%I64d",&n,&k);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	if(k>=n)
	{
		printf("%d\n",*max_element(a+1,a+n+1));
		return 0;
	}
	if(a[1]>*max_element(a+2,a+k+2))
	{
		printf("%d\n",a[1]);
		return 0;
	}
	for(i=2;i<=n;i++)
		if(a[i]>*max_element(a+i+1,a+i+k))
		{
			printf("%d\n",a[i]);
			return 0;
		}
	return 0;
}