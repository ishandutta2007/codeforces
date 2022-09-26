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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	if(n%2==1){cout<<"No\n"; return 0;}
	int sum=0; int mn=0;
	for(int i=0;i<n;i++)
	{
		sum+=(s[i]=='('?1:-1);
		mn=min(mn,sum);
	}
	if(sum!=0){cout<<"No\n"; return 0;}
	if(mn<=-2){cout<<"No\n"; return 0;}
	cout<<"Yes\n";
}