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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MOD = 1e9 + 7;

ll add(ll a, ll b)
{
	a+=b; a%=MOD; if(a<0) a+=MOD;
	return a;
}

ll subtr(ll a, ll b)
{
	a-=b; a%=MOD;
	if(a<0) a+=MOD;
	return a;
}

ll mult(ll a, ll b)
{
	a%=MOD; b%=MOD;
	return (a*b)%MOD;
}

ll modpow(ll a, ll b)
{	
	ll r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;	
}

ll inv6,inv30,inv42;

ll f(ll n, ll x3, ll x2, ll x1, ll x0)
{
	ll num = mult(x0,mult(n,mult(n+1,n+2)));
	ll num2 = add(add(x3, x3), mult(3*n+4, x1));
	num2 = subtr(num2, mult(3*(n+2), x2));
	num = add(num, num2);
	num = mult(num, inv6);
	return num;
}

ll S1(ll x) //sum of perfect squares from 1^2 to x^2
{
	if(x<=0) return 0;
	return mult(inv6, mult(x, mult(x+1, 2*x+1)));
}

ll S2(ll x) //sum from 1^4 to x^4
{
	if(x<=0) return 0;
	ll cur[6]={};
	cur[0]=1;
	for(int i=1;i<=5;i++) cur[i]=mult(cur[i-1],x);
	return mult(inv30, subtr(6*cur[5]+15*cur[4]+10*cur[3],cur[1]));
}

ll S3(ll x) //sum from 1^6 to x^6
{
	if(x<=0) return 0;
	ll cur[8]={};
	cur[0]=1;
	for(int i=1;i<=7;i++) cur[i]=mult(cur[i-1],x);
	return mult(inv42, subtr(6*cur[7]+21*cur[6]+21*cur[5]+cur[1], 7*cur[3]));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	inv6 = modpow(6, MOD-2); inv30 = modpow(30, MOD-2); inv42 = modpow(42,MOD-2);
	ll m; cin>>m;
	ll ans = 0;
	//count (0,0)
	const int C = 1000000;
	ans = add(ans, f(m,1,1,1,1));
	for(ll x = -C; x <= C; x++)
	{
		//x^2+y^2<=m
		if(x*x>m) continue;
		ll diff = m - x*x;
		ll maxsqrt = ceil(sqrt(ld(diff)));
		while(maxsqrt*maxsqrt>diff) maxsqrt--;
		//y is from -maxsqrt to maxsqrt;
		ll x0 = maxsqrt*2+1;
		if(x==0) x0--;
		ll s1 = S1(maxsqrt); ll s2 = S2(maxsqrt); ll s3 = S3(maxsqrt);
		s1=add(s1,s1); s2=add(s2,s2); s3=add(s3,s3);
		ll x1 = add(s1, mult(x0, x*x));
		ll x2 = add(mult(x0, mult(x*x,x*x)), add(mult(2*x*x, s1), s2));
		ll x3 = add(mult(x0, mult(x*x,mult(x*x,x*x))), add(mult(3*mult(x*x,x*x), s1), add(mult(3*x*x, s2), s3)));
		ans = add(ans, f(m, x3, x2, x1, x0));
		/*                                                                  
		for(ll y = -maxsqrt; y <= maxsqrt; y++)
		{
			if(x==0&&y==0) continue;
			if(y*y<=diff)
			{
				ll r=x*x+y*y;
				ans = add(ans, f(m, r*r*r,r*r,r,1));
			}
		}
		*/
	}
	cout<<ans<<'\n';
}