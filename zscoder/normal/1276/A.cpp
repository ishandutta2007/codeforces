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
	string s; cin>>s;
	int n=s.length();
	vi ans;
	string t="";
	vector<pair<char,int> > vec;
	for(int i=0;i<n;i++)
	{
		if(i>=2&&i+2<n&&s[i-2]=='t'&&s[i-1]=='w'&&s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
		{
			ans.pb(i);
		}
		else
		{
			vec.pb({s[i],i});
		}
	}
	for(int i=0;i<vec.size();i++)
	{
		if(i>=1&&i+1<vec.size())
		{
			string tmp;
			tmp+=vec[i-1].fi;
			tmp+=vec[i].fi;
			tmp+=vec[i+1].fi;
			if(tmp=="one"||tmp=="two")
			{
				ans.pb(vec[i].se);
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]+1<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}