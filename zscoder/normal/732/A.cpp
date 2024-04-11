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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
typedef pair<int,ii> iii;

bool check(int money, int k, int r)
{
	if(money%10==0) return true;
	if(money%10==r) return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k, r; cin>>k>>r;
	int ans = 1;
	while(1)
	{
		int money = k*ans;
		if(check(money,k,r))
		{
			break;
		}
		ans++;
	}
	cout << ans;
}