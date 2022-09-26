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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int b,k; cin>>b>>k;
	int ans =0;
	for(int i=0;i<k;i++)
	{
		int x; cin>>x;
		if(i==k-1) ans+=x;
		else
		{
			if(b&1) ans+=x;
		}
	}
	if(ans&1) cout<<"odd\n";
	else cout<<"even\n";
}