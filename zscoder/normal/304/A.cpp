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

bool issqr(int x)
{
	return (abs(double(sqrt(x))-round(sqrt(x)))<=ld(1e-9));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n; int ans=0;
	for(int a=1;a<=n;a++)
	{
		for(int b=a;b<=n;b++)
		{
			if(a*a+b*b>n*n) break;
			if(issqr(a*a+b*b))
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}