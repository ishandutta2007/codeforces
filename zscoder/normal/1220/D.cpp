#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<ll> a;
vector<ll> rem;

void solve(vector<ll> v, ll mul)
{
	int n=v.size();
	if(v.empty())
	{
		return ;
	}
	vector<ll> E,O;
	for(ll x:v)
	{
		if(x%2==0) E.pb(x);
		else O.pb(x);
	}
	if(O.size()>rem.size())
	{
		rem.clear();
		for(ll x:O) rem.pb(x*mul);
	}
	for(int i=0;i<E.size();i++) E[i]/=2;
	solve(E,mul*2);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	solve(a,1);
	set<ll> S;
	for(ll x:rem) S.insert(x);
	set<ll> T;
	for(ll x:a)
	{
		if(S.find(x)==S.end()) T.insert(x);
	}
	cout<<T.size()<<'\n';
	for(ll x:T)
	{
		cout<<x<<' ';
	}
	cout<<'\n';
}