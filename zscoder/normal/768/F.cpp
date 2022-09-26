#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1e9+7;
ll modpow(ll a,ll b)
{
	ll r=1;
	while(b)
	{
		if(b&1) r=(r*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return r;
}

ll inv(ll a)
{
	return modpow(a,MOD-2);
}

ll fact[300001];
ll ifact[300001];

ll mult(ll a, ll b)
{
	return (a*b)%MOD;
}

ll choose(ll n, ll r)
{
	if(n<r) return 0;
	if(n==r) return 1;
	if(r==0) return 1;
	return mult(fact[n],mult(ifact[r],ifact[n-r]));
}

ll solve(ll i, ll m)
{
	if(i==0&&m==0) return 1;
	else if(i==0) return 0;
	return choose(m-1,i-1);
}

ll add(ll a, ll b)
{
	ll res=(a+b);
	if(res>=MOD) res-=MOD;
	return res;
}

ll solve2(ll i, ll h, ll m)
{
	if(i==0&&m==0) return 1;
	else if(i==0) return 0;
	m-=(h-1)*i;
	if(m<i) return 0;
	return choose(m-1,i-1);
}


ll sf[200001];
ll sw2[200001];
ll sw[200001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll f, w,h;
	cin>>f>>w>>h;
	fact[0]=1;
	ifact[0]=1;
	for(int i = 1; i <= 250000; i++)
	{
		fact[i]=(fact[i-1]*i)%MOD;
		ifact[i]=inv(fact[i]);
	}
	h++;
	ll num = 0;
	ll denom = 0;
	//f first
	for(int i = 0; i <= f; i++) sf[i] = solve(i,f);
	for(int i = 0; i <= w; i++) sw2[i] = solve2(i,h,w);
	for(int i = 0; i <= w; i++) sw[i] = solve(i,w);
	for(int i = 1; i <= f; i++)
	{
		//i - 1 stacks of w
		ll ans = mult(sf[i],sw[i-1]);
		denom=add(denom,ans);
		//i stacks of w
		ans=mult(sf[i],sw[i]);
		denom=add(denom,ans);
	}
	//w first
	for(int i = 1; i <= w; i++)
	{
		ll ans = mult(sw[i],sf[i-1]);
		denom=add(denom,ans);
		//i stacks of w
		ans=mult(sw[i],sf[i]);
		denom=add(denom,ans);
	}
	for(int i = 1; i <= f; i++)
	{
		ll ans = mult(sf[i],sw2[i-1]);
		num=add(num,ans);
		//i stacks of w
		ans=mult(sf[i],sw2[i]);
		num=add(num,ans);
	}
	for(int i = 1; i <= w; i++)
	{
		ll ans = mult(sw2[i],sf[i-1]);
		num=add(num,ans);
		//i stacks of w
		ans=mult(sw2[i],sf[i]);
		num=add(num,ans);
	}
	//cerr<<num<<' '<<denom<<'\n';
	num=mult(num,inv(denom));
	cout<<num;
}