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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi gendivisors(ll n)
{
	vi ans;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i!=0) continue;
		ans.pb(i);
		if(i*i!=n) ans.pb(n/i);
	}
	return ans;
}

const ll INF=ll(1e18);
ll mult(ll a, ll b)
{
	if(a==0||b==0) return 0;
	if(a>=INF/b) return INF;
	return a*b;
}

ll lcm(ll a, ll b)
{
	ll g=__gcd(a,b);
	return mult(a/g,b);
}

void solve()
{
	int n; cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//check if max element is the answer
	sort(a.begin(),a.end());
	/*
	int ans = a[n-1]; //try first
	vi tmp = gendivisors(a[n-1]);
	bool pos=1;
	for(int i=0;i<n;i++)
	{
		if(a[n-1]%a[i]!=0){pos=0; break;}
	}
	if(pos&&(int(tmp.size())==n)){cout<<a[n-1]<<'\n'; return ;}
	*/
	ll ans=a[0];
	for(int i=0;i<n;i++)
	{
		ans=lcm(ans,a[i]);
	}
	if(ans==a[n-1])
	{
		ans=mult(ans,a[0]);
	}
	if(ans>=ll(1e13))
	{
		cout<<-1<<'\n'; return ;
	}
	vi tmp = gendivisors(ans);
	sort(tmp.begin(),tmp.end());
	if(tmp==a) {cout<<ans<<'\n'; return ;}
	else 
	{
		cout<<-1<<'\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t; while(t--) solve();
}