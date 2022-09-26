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

void solve()
{
	vi a;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; a.pb(x);
	}
	set<ii> S;
	bitset<111> marked;
	marked.reset();
	for(int i=0;i<n;i++) marked.set(i,1);
	for(int i=0;i<n;i++) S.insert({-a[i],i});
	int turns=0; int pre=-1;
	while(!S.empty())
	{
		int cur=-1;
		for(ii x:S)
		{
			if(!marked[x.se]) continue;
			cur=x.se;
			marked.set(cur,0);
			int val = -x.fi;
			S.erase(x);
			val--;
			if(val>0) S.insert({-val,cur});
			break;
		}
		if(cur==-1) break;
		turns++;
		if(pre!=-1) marked.set(pre,1);
		pre=cur;
	}
	if(turns%2==0) cout<<"HL\n";
	else cout<<"T\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}