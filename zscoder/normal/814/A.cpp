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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int a[1001];
int b[1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	vi pos;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0) pos.pb(i);
	}
	for(int i=0;i<k;i++) cin>>b[i];
	if(k>1)
	{
		cout<<"Yes\n";
	}
	else
	{
		a[pos[0]]=b[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]<=a[i-1])
			{
				cout<<"Yes\n";
				return 0;
			}
		}
		cout<<"No\n";
	}
}