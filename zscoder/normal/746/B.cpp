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

char ans[2111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	int l, r;
	int ptr = 0;
	if(n&1)
	{
		ans[n/2] = s[0];
		ptr++;
		l = n/2 - 1; r = n/2 + 1;
	}
	else
	{
		l = n/2 - 1; r = n/2;
	}
	for(;l>=0&&r<n; l--,r++)
	{
		ans[l] = s[ptr++];
		ans[r] = s[ptr++];
	}
	ans[n] = '\0';
	cout<<ans;
}