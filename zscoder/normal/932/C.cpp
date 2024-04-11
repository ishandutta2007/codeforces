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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,a,b;cin>>n>>a>>b;
	vi vec(n);
	for(ll i=0;n-i*a>=0;i++)
	{
		if((n-i*a)%b==0)
		{
			for(int j=0;j<i;j++)
			{
				for(int k=0;k<a;k++)
				{
					int cur = j*a+k; int nxt = j*a+(k+1)%a;
					vec[cur]=nxt;
				}
			}
			int id=i*a;
			for(int j=0;j<(n-i*a)/b;j++)
			{
				for(int k=0;k<b;k++)
				{
					int cur = id+j*b+k; int nxt = id+j*b+(k+1)%b;
					vec[cur]=nxt;
				}
			}
			for(int i=0;i<n;i++)
			{
				cout<<vec[i]+1;
				if(i+1<n) cout<<' ';
			}
			cout<<'\n';
			return 0;
		}
	}
	cout<<-1<<'\n';
}