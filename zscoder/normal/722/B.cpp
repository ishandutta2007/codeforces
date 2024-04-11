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

int p[101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	string t;
	getline(cin, t);
	for(int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		s += ' ';
		int cnt = 0; int wordcnt = 0; bool exvow = false;
		for(int j = 0; j < s.length(); j++)
		{
			if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y') 
			{
				cnt++; exvow = true;
			}
			else if(s[j] == ' ')
			{
				if(exvow) 
				{
					wordcnt++;
					exvow = false;
				}
			}
		}
		if(!(p[i] >= wordcnt && p[i] == cnt)){cout << "NO"; return 0;}
		//cerr << wordcnt << ' ' << cnt << '\n';
	}
	cout << "YES";
}