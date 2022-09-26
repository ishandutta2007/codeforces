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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int c[111];
int a[111];
int b[111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	for(int i=0;i<n;i++) c[i]=s[i]-'0';
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	const int MX = 10000;
	int ans=0;
	for(int i=0;i<=MX;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>=b[j])
			{
				if(i%a[j]==b[j]%a[j])
				{
					c[j]^=1;
				}
			}
		}
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			cnt+=c[j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
}