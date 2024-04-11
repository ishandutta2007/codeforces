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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int go(vi vec)
{
	cout<<"next"<<' ';
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i+1<vec.size()) cout<<' ';
	}
	cout<<'\n';
	fflush(stdout);
	int c; cin>>c;
	for(int i=0;i<c;i++)
	{
		string s; cin>>s;
	}
	return c;
}

int main()
{
	while(1)
	{
		go({2,3,4,5,6,7,8,9});
		int res = go({1,2,3,4,5,6,7,8,9});
		if(res==2)
		{
			break;
		}
	}
	while(1)
	{
		int res = go({0,1,2,3,4,5,6,7,8,9});
		if(res==1)
		{
			cout<<"done\n"; fflush(stdout); return 0;
		}
	}
}