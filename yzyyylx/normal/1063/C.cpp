#include<iostream>
#include<cstdio>
#define ll long long
#define M 1000000000
using namespace std;

ll n,mid;
char str[10];

int main()
{
	ll i,j,l,r,t;
	cin>>n;
	if(n==1)
	{
		puts("0 0");fflush(stdout);
		puts("10 8 20 8");fflush(stdout);
		return 0;
	}
	for(i=l=1,r=M-1; i<=n/2; i++)
	{
		mid=((l+r)>>1);
		printf("%lld %lld\n",mid,1ll);fflush(stdout);
		scanf("%s",str+1);
		if(str[1]=='b') r=mid-1;
		else l=mid+1;
	}
	n-=n/2;
	t=l+1;
	l=1,r=M-1;
	for(i=1; i<=n; i++)
	{
		mid=((l+r)>>1);
		printf("%lld %lld\n",1ll,mid);fflush(stdout);scanf("%s",str+1);
		if(str[1]=='b') r=mid-1;
		else l=mid+1;
	}
	printf("%lld %lld %lld %lld\n",1ll,l+1,t,1ll);fflush(stdout);
}