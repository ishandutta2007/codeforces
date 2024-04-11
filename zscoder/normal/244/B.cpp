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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

set<ll> S;

void solve(ll a, ll b, ll x, ll cur)
{
	if(cur>x) return ;
	S.insert(cur);
	if(a==0&&cur==0){}
	else solve(a,b,x,cur*10+a);
	solve(a,b,x,cur*10+b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x; cin>>x;
	for(int i=0;i<=9;i++)
	{
		for(int j=i+1;j<=9;j++)
		{
			solve(i,j,x,0);
		}
	}
	S.erase(0);
	cout<<S.size()<<'\n';
}