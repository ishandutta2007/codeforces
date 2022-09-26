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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	int cnt=0;
	for(int i=0;i<n;i++) cnt+=a[i];
	for(int z=0;z<k;z++)
	{
		int t; int x; cin>>t>>x;
		if(t==1)
		{
			x--;
			cnt-=a[x];
			a[x]^=1;
			cnt+=a[x];
		}
		else
		{
			if(cnt>=x)
			{
				cout<<1<<'\n';
			}
			else
			{
				cout<<0<<'\n';
			}
		}
	}
}