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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

void solve()
{
	string s; cin>>s;
	int ans=int(1e9);
	int n=s.length();
	for(int i=0;i<(1<<n);i++)
	{
		vi vec;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) vec.pb(1);
			else vec.pb(0);
		}
		bool pos=1;
		for(int j=0;j<n;j++)
		{
			if(s[j]!='?'&&s[j]-'0'!=vec[j]){pos=0; break;}
		}
		if(!pos) continue;
		//only possible ones
		int diff=0;
		int res=n;
		int turns_left[2] = {n/2,n/2};
		for(int j=0;j<n;j++)
		{
			//check if I can just stop here
			if(diff>turns_left[1]){res=j; break;}
			if(diff<-turns_left[0]){res=j; break;}
			if(vec[j])
			{
				if(j&1) diff--;
				else diff++;
			}
			turns_left[j&1]--;
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}