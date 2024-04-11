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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool ispal(string t)
{
	for(int i=0;i<t.length();i++)
	{
		if(t[i]!=t[int(t.length())-1-i]) return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s; int n=s.length();
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			string t;
			for(int k=i;k<=j;k++)
			{
				t+=s[k];
			}
			if(!ispal(t)) ans=max(ans,j-i+1);
		}
	}
	cout<<ans<<'\n';
}