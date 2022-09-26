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

map<string,int> ma;

string category(string name, int n)
{
	int better=0;
	for(auto s:ma)
	{
		if(s.se>ma[name])
		{
			better++;
		}
	}
	if(better*2>n) return "noob";
	if(better*5>n) return "random";
	if(better*10>n) return "average";
	if(better*100>n) return "hardcore";
	return "pro";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		int x; cin>>x;
		ma[s]=max(ma[s],x);
	}
	cout<<ma.size()<<'\n';
	for(auto X:ma)
	{
		cout<<X.fi<<' '<<category(X.fi,ma.size())<<'\n';
	}
}