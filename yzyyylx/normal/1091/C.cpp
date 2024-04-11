#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 1010
#define M 
using namespace std;

ll n;
vector<ll>ans;

inline ll calc(ll u)
{
	ll i,j;
	return (1+n-u+1)*(n/u)/2;
}

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i*i<=n;i++)
	{
		if(n%i) continue;
		ans.push_back(calc(i));
		if(i*i!=n) ans.push_back(calc(n/i));
	}
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++) printf("%lld ",ans[i]);
}