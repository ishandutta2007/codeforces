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

const int LG = 30;
//0 to LG bits
int xr[111111];
int marked[11111];

int a(int i, int j)
{
	cout<<"and "<<i+1<<' '<<j+1<<'\n';
	fflush(stdout);
	int x; cin>>x; return x;
}

int o(int i, int j)
{
	cout<<"or "<<i+1<<' '<<j+1<<'\n';
	fflush(stdout);
	int x; cin>>x; return x;
}

void answer(int x)
{
	cout<<"finish "<<x<<'\n';
	fflush(stdout);
	exit(0);
}

int main()
{
	int n,k; cin>>n>>k;
	int firstval = 0;
	for(int i=1;i<n;i++)
	{
		int x = a(0,i);
		int y = o(0,i);
		for(int j=0;j<=LG;j++)
		{
			int andyes = 0;
			int oryes = 0;
			if(x&(1<<j)) andyes=1;
			if(y&(1<<j)) oryes=1;
			if(andyes!=oryes)
			{
				xr[i]^=(1<<j); 
			}
			else
			{
				marked[j]=1;
				if(andyes) firstval|=(1<<j);
			}
		}
	}
	int x = a(1,2);
	int y = o(1,2);
	for(int i=0;i<=LG;i++)
	{
		int andyes = 0;
		int oryes = 0;
		if(x&(1<<i)) andyes=1;
		if(y&(1<<i)) oryes=1;
		if(!marked[i])
		{
			assert(andyes==oryes);
			//they are different from firstval tho
			if(!andyes) firstval|=(1<<i);
		}
	}	
	vi ans;
	ans.pb(firstval);
	for(int i=1;i<n;i++) ans.pb(firstval^xr[i]);
	sort(ans.begin(),ans.end());
	answer(ans[k-1]);
}