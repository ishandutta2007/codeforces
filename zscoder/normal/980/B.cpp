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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

char a[5][111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]='.';
		}
	}
	if(k%2==0)
	{
		for(int i=1;i<=k/2;i++)
		{
			a[1][i]=a[2][i]='#';
		}
	}
	else
	{
		if(k<=n-2)
		{
			for(int i=n/2-k/2;i<=n/2+k/2;i++)
			{
				a[1][i]='#';
			}
		}
		else
		{
			for(int i=1;i<=n-2;i++)
			{
				a[1][i]='#';
			}
			k-=(n-2);
			int l=1; int r=n-2;
			for(int i=0;i<k/2;i++)
			{
				a[2][l]=a[2][r]='#';
				l++; r--;
			}
		}
	}
	cout<<"YES\n";
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j];
		}
		cout<<'\n';
	}
}