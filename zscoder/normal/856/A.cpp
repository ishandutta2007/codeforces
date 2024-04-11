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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

bool used[1000001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	for(int z=0;z<t;z++)
	{
		int n; cin>>n;
		memset(used,0,sizeof(used));
		vi a(n); vi b(n);
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				used[a[j]-a[i]]=1;
			}
		}
		ll mindiff=0;
		for(int i=1;i<=1000000;i++)
		{
			bool pos=0;
			for(int j=1;j<=n-1&&i*j<=1000000;j++)
			{
				if(i*j<=1000000&&used[i*j])
				{
					pos=1; break;
				}
			}
			if(!pos)
			{
				mindiff=i;
				break;
			}
		}

		b[0]=1;
		for(int i=1;i<n;i++)
		{
			b[i]=b[i-1]+mindiff;
		}
		cout<<"YES\n";
		for(int i=0;i<n;i++)
		{
			cout<<b[i];
			if(i+1<n) cout<<' ';
		}
		cout<<'\n';
	}
}