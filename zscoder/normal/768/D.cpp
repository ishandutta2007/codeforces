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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ld dp[10001][1001];

void dodp(int k)
{
	dp[1][1] = 2000;
	for(int i = 2; i <= 10000; i++)
	{
		for(int j = 1; j <= min(k, i); j++)
		{
			//dp[i][j] = dp[i-1][j];
			if(j>1)
			{
				dp[i][j] = (ld(dp[i-1][j-1])*(ld((k-j+1))/ld(k)));
			}
			dp[i][j]+=(ld(dp[i-1][j]))*ld(ld(j)/ld(k));
			//if(j==1000&&i>=8000)cerr<<i<<' '<<j<<' '<<fixed<<setprecision(9)<<dp[i][j]<<'\n';
		}
	}
}
const ld eps = 1e-7;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k,q; cin>>k>>q;
	dodp(k);	
	for(int i = 0; i < q; i++)
	{
		ld x; cin>>x;
		for(int j = 1; j <= 10000; j++)
		{
			if(dp[j][k]>=x-eps)
			{
				cout<<j<<'\n';
				break;
			}
		}
	}
}