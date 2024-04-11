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
	p=num[3];
	sort(num+1,num+n+1);
	cout<<2+(num[1]^p);
}