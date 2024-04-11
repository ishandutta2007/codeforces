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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int color[82];
int a[82][82];
int d[11][82];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin>>n; int m; cin>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	int ans = 1e9+7;
	while ((double) clock() / CLOCKS_PER_SEC < 2.89) 
	{
		color[0]=1;
		for(int i=1;i<n;i++) color[i]=mrand()&1;
		for(int i=0;i<n;i++)
		{
			if(i==0||color[i]==color[0]) d[1][i]=1e9+8;
			else d[1][i]=a[0][i];
			for(int c=2;c<=m;c++) d[c][i]=1e9+8;
		}
		for(int c=2;c<=m;c++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i!=j&&color[i]!=color[j]) d[c][j]=min(d[c][j],d[c-1][i]+a[i][j]);
				}
			}
		}
		ans=min(ans,d[m][0]);
	}
	cout<<ans<<'\n';
}