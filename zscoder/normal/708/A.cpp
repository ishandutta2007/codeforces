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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n = s.length(); bool changed = false;
	for(int i = 0; i < n; i++)
	{
		if(!changed)
		{
			if(s[i] != 'a')
			{
				s[i]--;
				changed = true;
				continue;
			}
		}
		else
		{
			if(s[i] != 'a')
			{
				s[i]--;
				continue;
			}
			else
			{
				cout << s;
				return 0;
			}
		}
	}
	if(!changed)
	{
		s[n - 1] = 'z';
	}
	cout << s;
}