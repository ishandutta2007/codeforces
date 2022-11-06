#include<stdio.h>
#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
long long a[300002][2],s[300002],t[300002],maxn;
int n,i;
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld",&a[i][0]);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i][1]);
		s[i]=s[i-1]+a[i][0]+a[i][1];
	}
	for(i=2;i<=(n<<1);i++)t[0]+=a[min(i,(n<<1)+1-i)][(i-1)/n]*(i-1);
	for(i=2;i<=(n<<1);i++)t[1]+=a[min(i-1,(n<<1)-i+2)][(i/(n+2))^1]*(i-1);
	maxn=max(t[0],t[1]);
	for(i=2;i<=n-1;i++)
	{
		t[i]=t[i-2]+((s[n]-s[i-1])<<1)-(a[i-1][(i&1)^1]+a[i][(i&1)^1])*((n-i+1)<<1);
		maxn=max(maxn,t[i]);
	}
	printf("%lld",maxn);
	return 0;
}