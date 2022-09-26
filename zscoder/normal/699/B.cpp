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

int r[1111];
int c[1111];
char a[1111][1111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m; int sum=0;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		for(int j=0;j<m;j++)
		{
			if(s[j]=='*') {r[i]++; c[j]++; sum++;}
			a[i][j]=s[j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(sum==r[i]+c[j]-(a[i][j]=='*')){cout<<"YES\n"<<i+1<<' '<<j+1<<'\n'; return 0;}
		}
	}cout<<"NO\n";
}