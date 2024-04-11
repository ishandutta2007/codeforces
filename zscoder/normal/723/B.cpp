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
	int ans1 = 0; int ans2 = 0;
	bool in = false; bool inword = false; int cur = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '(')
		{
			in = true;
			if(inword)
			{
				ans1 = max(ans1, cur);
				inword = false;
				cur = 0;
			}
		}
		else if(s[i] == ')')
		{
			in = false;
			if(inword)
			{
				ans2++;
				inword = false;
				cur = 0;
			}
		}
		else if(s[i] == '_')
		{
			if(inword)
			{
				if(!in)
				{
					ans1 = max(ans1, cur);
					inword = false;
					cur = 0;
				}
				else
				{
					ans2++;
					inword = false;
					cur = 0;
				}
			}
		}
		else
		{
			if(!inword) inword = true;
			cur++;
			if(i == n - 1)
			{
				ans1 = max(ans1, cur);
			}
		}
	}
	cout << ans1 << ' ' << ans2;
}