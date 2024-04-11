#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 1001000
#define M 998244353
using namespace std;

ll n,ans,hz[N];

int main()
{
	ll i,j;
	cin>>n;
	hz[n]=n;
	for(i=n-1;i>=1;i--) hz[i]=hz[i+1]*i%M;
	ans=hz[1];
	for(i=2;i<=n;i++)
	{
		ans+=hz[i+1]*(i-1)%M*(n-i)%M;
		ans%=M;
	}
	cout<<ans;
}