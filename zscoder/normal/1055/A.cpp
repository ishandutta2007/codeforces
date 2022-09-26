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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[1111];
int b[1111];
bool vis[1111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);	
	int n,s; cin>>n>>s;
	s--;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++)
	{
		if(a[0]&&a[i]) vis[i]=1;
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			if(vis[i]&&b[i]&&b[j])
			{
				vis[j]=1;
			}
		}
	}
	if(vis[s]) cout<<"YES\n";
	else cout<<"NO\n";
}