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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	if(s[3] >= '6')
	{
		s[3] = '0';
	}
	if(n == 12)
	{
		if(s[0] >= '2')
		{
			if(s[1] == '0') s[0] = '1';
			else s[0] = '0';
		}
		else if(s[0] == '1')
		{
			if(s[1] >= '3') s[1] = '0';
		}
		else if(s[0] == '0' && s[1] == '0')
		{
			s[1] = '1';
		}
	}
	else
	{
		if(s[0] >= '3')
		{
			if(s[1] == '0') s[0] = '1';
			else s[0] = '0';
		}
		else if(s[0] == '2')
		{
			if(s[1] >= '4') s[1] = '0';
		}
	}
	cout << s;
}