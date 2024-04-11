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

string a[333];
int cnt[5][3];

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	memset(cnt,0,sizeof(cnt));
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			k+=(a[i][j]!='.');
			if(a[i][j]=='O') cnt[(i+j)%3][1]++;
			if(a[i][j]=='X') cnt[(i+j)%3][0]++;
		}
	}
	int changeid = 0; int val = int(1e9);
	for(int i=0;i<3;i++)
	{
		if(cnt[i][1]+cnt[(i+1)%3][0]<val)
		{
			val=cnt[i][1]+cnt[(i+1)%3][0];
			changeid=i;
		}
	}
	int c=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int val=(i+j)%3;
			if(val==changeid)
			{
				if(a[i][j]=='O') 
				{
					a[i][j]='X'; c++;
				}
			}
			else if(val==(changeid+1)%3)
			{
				if(a[i][j]=='X') 
				{
					a[i][j]='O'; c++;
				}
			}
		}
	}
	assert(c<=k/3);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}