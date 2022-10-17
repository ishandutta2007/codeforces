#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,c[N],s[N];

ll ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&s[i]);
		ll k=s[i]/c[i];
		printf("%lld\n",1ll*k*k*(c[i]-s[i]%c[i])+1ll*(k+1)*(k+1)*(s[i]%c[i]));
	}
}