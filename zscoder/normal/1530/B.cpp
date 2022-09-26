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

int a[35][35];
int n,m; 
bool valid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m);
}

void solve()
{
	cin>>n>>m;
	int cnt1=0; 
	int cnt2=0;
	vector<ii> vec;
	memset(a,0,sizeof(a));
	for(int i=0;i<m;i++)
	{
		vec.pb({0,i});
	}
	for(int i=0;i<n;i++)
	{
		vec.pb({i,m-1});
	}
	for(int i=m-1;i>=0;i--)
	{
		vec.pb({n-1,i});
	}
	for(int i=n-1;i>=0;i--)
	{
		vec.pb({i,0});
	}
	for(ii e:vec)
	{
		int pos=1;
		int x=e.fi; int y=e.se;
		for(int i=-1;i<=1;i++)
		{
			for(int j=-1;j<=1;j++)
			{
				if(valid(x+i,y+j)&&a[x+i][y+j]){pos=0; break;}
			}
		}
		if(pos) a[x][y]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j];
		}
		cout<<'\n';
	}
	cout<<'\n';
	//cerr<<cnt1<<' '<<cnt2<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}