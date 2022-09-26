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

int n,m; 

bool isvalid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m);
}

int a[333][333];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void solve()
{
	cin>>n>>m;
	bool pos=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int cnt=0;
			cin>>a[i][j];
			for(int k=0;k<4;k++)
			{
				if(isvalid(i+dx[k],j+dy[k]))
				{
					cnt++;
				}
			}
			if(a[i][j]>cnt)
			{
				pos=0;
			}
			a[i][j]=cnt;
		}	
	}
	if(!pos)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<a[i][j];
				if(j+1<m) cout<<' ';
			}
			cout<<'\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}