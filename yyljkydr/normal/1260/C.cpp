#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,a,b,k;

ll ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&k);
		int g=__gcd(a,b);
		a/=g;
		b/=g;
		if(a>b)
			swap(a,b);
		if(a==b)
			puts("OBEY");
		else
		{
			b-=2;
			int tot=b/a+1;
			puts(tot<k?"OBEY":"REBEL");
		}
	}
}