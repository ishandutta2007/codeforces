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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
typedef vector<ll>::iterator vit;
 
long long k;
 
int n;
long long dp[5007][9];
int co[5007];
 
string slo="-FESTIVAL";
 
string wyn;
 
int main()
{
	scanf("%lld", &k);
	dp[0][0]=1;
	while(dp[n][7]*100<k)
	{
		n++;
		co[n]=(n-1)%7+1;
		for (int i=0; i<=7; i++)
			dp[n][i]=dp[n-1][i];
		dp[n][co[n]]+=dp[n-1][co[n]-1];
	}
	for (int i=n; i; i--)
	{
		while(k && dp[i][7]<=k)
		{
			k-=dp[i][7];
			wyn+='L';
		}
		wyn+=slo[co[i]];
	}
	reverse(wyn.begin(), wyn.end());
	assert(wyn.length()<=200);
	cout << wyn << ' ' << "FESTIVAL" << endl;
	return 0;
}