#include<stdio.h>
#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
long long m,n,a,i,j,k,cnt1,cnt2;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		cnt1=cnt2;
		cnt2+=a;
		printf("%lld ",cnt2/m-cnt1/m);                   
	}
	return 0;
}