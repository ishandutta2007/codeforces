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

bool good(int x)
{
	x = abs(x);
	while(x)
	{
		if(x%10==8) return 1;
		x/=10;
	}
	return 0;	
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a; cin >> a;
	for(int i = 1; i <= 100; i++)
	{
		if(good(a+i)){cout<<i;return 0;}
	}
}