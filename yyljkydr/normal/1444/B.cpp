#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7,P=998244353;

typedef long long ll;

int n,a[N];

ll s;

int inv(int x)
{
	ll b=P-2,a=x;
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n*2+1);
	for(int i=n+1;i<=n*2;i++)
		s+=a[i]-a[i-n];
	s%=P;
	for(int i=n+1;i<=n*2;i++)
		s=s*i%P*inv(i-n)%P;
	printf("%lld\n",s);
}