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

int a[101];
int cc = 0;
bool vis[101];
void dfs(int u)
{
	//cerr<<u<<'\n';
	cc++;
	vis[u]=1;
	if(!vis[a[u]]) dfs(a[u]);
}

ll lcm(ll a, ll b)
{
	return (a*b)/__gcd(a,b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vi vec(n);
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		a[i]--;
		vec[i] = a[i];
	}
	sort(vec.begin(),vec.end());
	for(int i = 0; i < n; i++)
	{
		if(vec[i]!=i)
		{
			cout<<-1;
			return 0;
		}
	}
	vi cyc;
	for(int i = 0; i < n; i++)
	{
		if(!vis[i])
		{
			cc=0;
			dfs(i);
			cyc.pb(cc);
		}
	}
	ll ans = 1;
	for(int i = 0; i < cyc.size(); i++)
	{
		if(cyc[i]%2==0) cyc[i]/=2;
		ans = lcm(ans,cyc[i]);
	}
	cout<<ans;
}