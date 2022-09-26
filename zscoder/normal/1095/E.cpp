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

int minpref[1111111];
int maxsuf[1111111];
int S[1111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	for(int i=1;i<=n;i++)
	{
		int v=(s[i-1]=='('?1:-1);
		S[i]=S[i-1]+v;
		minpref[i]=min(minpref[i-1],S[i]);
	}
	for(int i=n;i>=1;i--)
	{
		maxsuf[i]=max(maxsuf[i+1],S[n]-S[i-1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum = S[n];
		int v = (s[i-1]=='('?1:-1);
		int newv = v*-1;
		sum-=v; sum+=newv;
		if(sum==0)
		{
			if(minpref[i-1]>=0&&S[i-1]+newv>=0&&maxsuf[i+1]<=0)
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}