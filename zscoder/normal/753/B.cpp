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

ii query(string s)
{
	cout<<s<<'\n';
	fflush(stdout);
	ii tmp;
	cin>>tmp.fi>>tmp.se;
	return tmp;
}

int main()
{
	vi perm;
	for(int i = 0; i < 10; i++)
	{
		string s(4,char('0'+i));
		ii tmp = query(s);
		if(tmp.fi+tmp.se>0)
		{
			perm.pb(i);
		}
	}
	do
	{
		string s;
		for(int i = 0; i < 4; i++)
		{
			s+=char('0'+perm[i]);
		}
		if(query(s).fi!=4) continue;
		return 0;
	}while(next_permutation(perm.begin(),perm.end()));
}