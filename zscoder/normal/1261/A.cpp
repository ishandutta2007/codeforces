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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	int n,k; cin>>n>>k;
	string s; cin>>s;
	string t;
	for(int i=0;i<k-1;i++) t+="()";
	int rem = n-2*(k-1);
	rem/=2;
	for(int i=0;i<rem;i++)
	{
		t+="(";
	}
	for(int i=0;i<rem;i++)
	{
		t+=")";
	}
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		if(s[i]==t[i]) continue;
		for(int j=i+1;j<n;j++)
		{
			if(s[j]==t[i])
			{
				vec.pb({i,j});
				reverse(s.begin()+i,s.begin()+j+1);
				break;
			}
		}
	}
	cout<<vec.size()<<'\n';
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i].fi+1<<' '<<vec[i].se+1<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}