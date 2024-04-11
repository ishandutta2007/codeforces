#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 200100
using namespace std;

ll n,m,ans,num[N],sy[N];
vector<P>a,b;

int main()
{
	ll i,j,k,p,q;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]);
	for(i=1;i<=n;i<<=1)
	{
		for(j=1;j<=n;j+=i)
		{
			for(k=j;k<i+j-1;k++)
			{
				if(num[k]>num[k+1]) break;
			}
			if(k==i+j-1) ans=max(ans,i);
		}
	}
	cout<<ans;
}