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

string insert(string s, int pos, char c)
{
	string a = s.substr(0, pos);
	a += c;
	if(pos < s.length()) a += s.substr(pos, s.length() - pos);
	return a;
}

bool ispal(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] != s[s.length() - 1 - i]) return false;
	}
	return true; 
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i <= s.length(); i++)
	{
		for(int j = 0; j < 26; j++)
		{
			string tmp = insert(s, i, j+'a');
			if(ispal(tmp)){cout<<tmp; return 0;}
		}
	}
	cout << "NA"; return 0;
}