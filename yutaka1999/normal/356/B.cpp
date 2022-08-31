#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 1000005

using namespace std;
typedef long long int ll;

ll gcd(ll x,ll y)
{
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
ll lcm(ll x,ll y)
{
	return x/gcd(x,y)*y;
}
char a[SIZE],b[SIZE];
ll sum[SIZE][26];
int main()
{
	ll n,m;
	scanf("%I64d %I64d",&n,&m);
	scanf("%s",&a);
	scanf("%s",&b);
	ll sa=strlen(a),sb=strlen(b);
	ll gs=gcd(sa,sb),ls=lcm(sa,sb);
	ll kk=n*sa/ls;
	for(ll i=0;i<sa;i++) sum[i%gs][a[i]-'a']++;
	ll ret=ls;
	for(ll i=0;i<sb;i++)
	{
		ret-=sum[i%gs][b[i]-'a'];
	}
	ret*=kk;
	printf("%I64d\n",ret);
	return 0;
}