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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MOD = 1e9 + 7;

ll pl(ll a, ll b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}

vi add(vi &v1, vi &v2, int sign)
{
	vi v(v1.size());
	for(int i=0;i<v1.size();i++)
	{
		if(sign==1) v[i]=pl(v1[i],v2[i]);
		else v[i]=pl(v1[i],MOD-v2[i]);
	}
	return v;
}

ll fact[400001];
ll ifact[400001];

ll modpow(ll a, ll b)
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

ll ncr(ll n, ll k)
{
	if(k==0) return 1;
	if(n<k) return 0;
	ll ans=fact[n];
	ans=(ans*ifact[k])%MOD;
	ans=(ans*ifact[n-k])%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}

vector<ll> a;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fact[0]=1;
	ifact[0]=1;
	for(int i=1;i<=220000;i++)
	{
		fact[i]=(fact[i-1]*i)%MOD;
		ifact[i]=modpow(fact[i],MOD-2);
	}
	int n; cin>>n;
	//n=200000;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sign=1;
	while(n>1&&n%4!=0)
	{
		vector<ll> b(n-1);
		for(int i=0;i<n-1;i++)
		{
			if(sign==1) b[i]=pl(a[i],a[i+1]);
			else b[i]=pl(a[i],MOD-a[i+1]);
			sign*=-1;
		}
		a=b;
		n--;
	}
	if(n==1)
	{
		cout<<a[0]<<'\n';
		return 0;
	}
	else
	{
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			ll coeff = ncr(n/2-1,i/2);
			if(i%2==1&&sign==1)
			{
				coeff=MOD-coeff;
			}
			ans=pl(ans,(coeff*a[i])%MOD);
		}
		ans%=MOD;
		if(ans<0) ans+=MOD;
		cout<<ans<<'\n';
	}
	/*
	int n;cin>>n;
	vector<vi> tmp;
	for(int i=0;i<n;i++)
	{
		vi vec(n,0);
		vec[i]=1;
		tmp.pb(vec);
	}
	int sign=-1;
	for(int i=0;i<n-1;i++)
	{
		vector<vi> cur;
		for(int j=0;j+1<tmp.size();j++)
		{
			cur.pb(add(tmp[j],tmp[j+1],sign));
			sign*=-1;
		}
		tmp=cur;
	}
	for(int i=0;i<tmp[0].size();i++)
	{
		cout<<tmp[0][i]<<' ';
	}
	*/
}