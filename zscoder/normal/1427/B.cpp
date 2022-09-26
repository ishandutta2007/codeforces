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

void solve()
{
	int n,k; cin>>n>>k;
	string s; cin>>s;
	vector<int> pos;
	int cnt=0; int bad=0;
	for(int i=0;i<n;i++)
	{
		cnt+=(s[i]=='W');
		if(s[i]=='W') pos.pb(i);
	}
	int tot=cnt+k;
	if(tot>=n)
	{
		cout<<2*n-1<<'\n'; return ;
	}
	vi runs; 
	for(int i=0;i<n;i++)
	{
		if(s[i]=='W')
		{
			if(i==0) bad++;
			else if(s[i-1]!='W') bad++;
		}
	}
	for(int i=1;i<pos.size();i++)
	{
		if(pos[i]-pos[i-1]-1>=1) runs.pb(pos[i]-pos[i-1]-1);
	}
	sort(runs.begin(),runs.end());
	for(int i=0;i<runs.size();i++)
	{
		if(k>=runs[i])
		{
			k-=runs[i]; bad--;
		}
		else break;
	}
	if(tot>0) bad=max(bad,1);
	cout<<2*tot-bad<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t; while(t--) solve();
}