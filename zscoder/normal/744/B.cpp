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

ll tmp[1001];
int n; 
ll ans[1001];

void query(int pos, bool bit)
{
	vi vec;
	for(int i = 0; i < n; i++)
	{
		if(i&(1<<pos))
		{
			if(bit) vec.pb(i);
		}
		else
		{
			if(!bit) vec.pb(i);
		}
	}
	if(vec.empty()) return ;
	cout<<vec.size()<<'\n';
	for(int i = 0; i < vec.size(); i++)
	{
		cout<<vec[i]+1<<' ';
	}
	cout<<'\n';
	fflush(stdout);
	for(int i = 0; i < n; i++)
	{
		cin>>tmp[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(i&(1<<pos))
		{
			if(!bit)
			{
				ans[i] = min(ans[i], tmp[i]);
			}
		}
		else
		{
			if(bit)
			{
				ans[i] = min(ans[i], tmp[i]);
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		ans[i] = ll(1e18);
	}
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			query(i,j);
		}
	}
	cout<<-1<<'\n';
	for(int i = 0; i < n; i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	fflush(stdout);
	
}