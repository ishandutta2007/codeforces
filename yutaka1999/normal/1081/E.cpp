#include <bits/stdc++.h>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll X[SIZE];

int main()
{
	int n;
	scanf("%d",&n);n/=2;
	ll now=0;
	for(int i=0;i<n;i++) scanf("%lld",&X[2*i+1]);
	for(int i=0;i<n;i++)
	{
		ll s=-1,t=-1;
		for(ll j=1;j*j<=X[2*i+1];j++)
		{
			if(X[2*i+1]%j==0&&j%2==(X[2*i+1]/j)%2)
			{
				ll a=(X[2*i+1]/j-j)/2;
				ll b=(X[2*i+1]/j+j)/2;
				//printf("*%lld * %lld %lld : %lld %lld\n",X[i],j,X[i]/j,a,b);
				if(a>now)
				{
					if(s==-1||b<t) s=a,t=b;
				}
			}
		}
		if(s==-1)
		{
			puts("No");
			return 0;
		}
		X[2*i]=s*s-now*now;
		now=t;
		//printf("%lld\n",now);
	}
	puts("Yes");
	for(int i=0;i<2*n;i++) printf("%lld ",X[i]);
	puts("");
	return 0;
}