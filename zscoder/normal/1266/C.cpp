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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[555][555];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	if(n+m==2)
	{
		cout<<0<<'\n';
	}
	else
	{
		if(n>=m)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					a[i][j]=(m+1+i)*(j+1);
				}
			}
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					a[i][j]=(i+1)*(n+j+1);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<a[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
}