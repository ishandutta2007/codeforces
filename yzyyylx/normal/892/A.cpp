#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

ll n,m1,m2,sum;

int main()
{
	ll i,j,p;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		sum+=p;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		if(p>m1) m2=m1,m1=p;
		else if(p>m2) m2=p;
	}
	m1+m2>=sum?printf("YES"):printf("NO");
}