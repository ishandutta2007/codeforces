#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll T,a,b;

int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		if((a+b)&1)
		{
			puts("-1");
			continue;
		}
		if(a==b) puts(a?"1":"0");
		else puts("2");
	}
}