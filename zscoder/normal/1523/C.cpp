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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[1111];
void out(vi &v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i];
		if(i+1<v.size()) cout<<".";
	}
	cout<<'\n';
}

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int> vec;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			vec.pb(1);
		}
		else
		{
			while(a[i]!=vec.back()+1)
			{
				vec.pop_back();
			}
			assert((!vec.empty())&&(a[i]==vec.back()+1));
			vec[int(vec.size())-1]++;
		}
		out(vec);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}