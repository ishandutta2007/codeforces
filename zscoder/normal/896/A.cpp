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

string base = "What are you doing at the end of the world? Are you busy? Will you save us?";
string pref = "What are you doing while sending \"";
string mid = "\"? Are you busy? Will you send \"";
string en = "\"?";

const ll INF=ll(2e18);
ll dp[111111];

ll add(ll a, ll b)
{
	a+=b;
	if(a>INF) a=INF;
	return a;
}

ll len(ll x)
{
	if(dp[x]!=-1) return dp[x];
	if(x==0) return base.length();
	return (dp[x]=add(pref.length()+mid.length()+en.length(),add(len(x-1),len(x-1))));
}

char solve(int n, ll k)
{
	if(n==0)
	{
		if(k>=base.length()) return '.';
		else return base[k];
	}
	if(k<pref.length())
	{
		return pref[k];
	}
	k-=pref.length();
	if(k<len(n-1))
	{
		return solve(n-1,k);
	}
	k-=len(n-1);
	if(k<mid.length())
	{
		return mid[k];
	}
	k-=mid.length();
	if(k<len(n-1))
	{
		return solve(n-1,k);
	}
	k-=len(n-1);
	if(k<en.length())
	{
		return en[k];
	}
	else return '.';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp,-1,sizeof(dp));
	int q; cin>>q;
	while(q--)
	{
		int n; cin>>n;
		ll x; cin>>x;
		x--; 
		cout<<solve(n,x);
	}
	cout<<'\n';
}