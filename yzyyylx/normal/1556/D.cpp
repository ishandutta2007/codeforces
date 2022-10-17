#include<bits/stdc++.h>
#define ll long long
#define Ul unsigned long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100100
using namespace std;

ll T,n,m,num[N];

inline ll ask(ll u,ll v)
{
	ll a,b;
	printf("and %lld %lld\n",u,v);fflush(stdout);
	scanf("%lld",&a);
	printf("or %lld %lld\n",u,v);fflush(stdout);
	scanf("%lld",&b);
	return a+b;
}

int main()
{
	ll i,j,a,b,c;
	cin>>n>>m;
	a=ask(1,2),b=ask(1,3),c=ask(2,3);
	num[1]=(a+b+c)/2-c;
	num[2]=(a+b+c)/2-b;
	num[3]=(a+b+c)/2-a;
	for(i=4;i<=n;i++) num[i]=ask(1,i)-num[1];
	sort(num+1,num+n+1);
	printf("finish %lld",num[m]);
}