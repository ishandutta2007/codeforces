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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[1111][1111];
vi rows[1111];
vi cols[1111];
int rr[1111][1111];
int rc[1111][1111];

int main()
{
	int n,m; scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			rows[i].pb(a[i][j]);
			cols[j].pb(a[i][j]);
		}
	}
	for(int i=0;i<n;i++) 
	{
		sort(rows[i].begin(),rows[i].end()); rows[i].erase(unique(rows[i].begin(),rows[i].end()),rows[i].end());
		for(int j=0;j<m;j++)
		{
			rr[i][j]=lower_bound(rows[i].begin(),rows[i].end(),a[i][j])-rows[i].begin();
		}
	}
	for(int j=0;j<m;j++) 
	{
		sort(cols[j].begin(),cols[j].end()); cols[j].erase(unique(cols[j].begin(),cols[j].end()),cols[j].end());
		for(int i=0;i<n;i++)
		{
			rc[i][j]=lower_bound(cols[j].begin(),cols[j].end(),a[i][j])-cols[j].begin();
		}
	}
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<m;j++)
		{
			int mx=max(rr[i][j],rc[i][j]);
			int labr=rows[i].size()+(mx-rr[i][j]);
			int labc=cols[j].size()+(mx-rc[i][j]);
			printf("%d",max(labr,labc));
			if(j+1<m) printf(" ");
		}
		printf("\n");
	}
}