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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1e9 + 7;

ll b;
bool solve(ll x, vector<ll> dq)
{
	if(x==b)
	{
		cout << "YES\n";
		cout << dq.size() << '\n';
		for(int i = 0; i < dq.size(); i++)
		{
			cout << dq[i] << ' ';
		}
		return true;
	}
	if(x>b) return false;
	dq.pb(x*2LL);
	bool z = solve(x*2LL, dq);
	if(z) return true;
	dq.pop_back();
	dq.pb(x*10LL + 1LL);
	z = solve(dq.back(), dq);
	if(z) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a; cin>>a>>b;
	vector<ll> tmp;
	tmp.pb(a);
	if(!solve(a, tmp))
	{
		cout << "NO";
	}
}