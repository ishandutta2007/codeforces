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
int cnter[26];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m; cin >> m;
	string s; cin >> s;
	int n = int(s.length());
	for(int i = 0; i < n; i++) cnter[s[i]-'a']++;
	vi pos;
	string ans;
	vi pos2;
	pos.pb(-1); pos.pb(n);
	pos2.pb(-1); pos2.pb(n);
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(s[j] == 'a' + i)
			{
				pos.pb(j);
			}
		}
		sort(pos.begin(),pos.end());
		bool p = true;
		for(int j = 1; j < pos.size(); j++)
		{
			if(pos[j] - pos[j-1] > m)
			{
				p = false; break;
			}
		}
		if(!p)
		{
			continue;
		}
		for(int j = 0; j < n; j++)
		{
			if(s[j] < 'a' + i)
			{
				pos2.pb(j);
			}
		}
		sort(pos2.begin(),pos2.end());
		int ptr = 0; int cnt = 0;
		for(int j = 1; j < pos2.size(); j++)
		{
			int cur = pos2[j-1];
			int nxt = pos2[j];
			//cerr<<cur<<' '<<nxt<<'\n';
			while(nxt-cur>m)
			{
				//cerr<<cur<<' '<<nxt<<'\n';
				ptr = upper_bound(pos.begin(),pos.end(),cur+m)-pos.begin();
				ptr--;
				cur = pos[ptr];
				cnt++;
			}
		}
		for(int j = 0; j < i; j++)
		{
			for(int k = 0; k < cnter[j]; k++)
			{
				ans += char('a'+j);
			}
		}
		for(int j = 0; j < cnt; j++) ans += char('a'+i);
		cout << ans;
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		
	}
}