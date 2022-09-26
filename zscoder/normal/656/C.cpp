#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;

#define fi first
#define se second
#define pb push_back
#define mp make_pair


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("AMAEXPER.in", "r", stdin);
	string s;
	cin >> s;
	ll res = 0;
	for(int i = 0; i < int(s.length()); i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			res += (s[i] - 'A' + 1);
		}
		else if(s[i] >= 'a' && s[i] <= 'z')
		{
			res -= (s[i] - 'a' + 1);
		}
	}
	cout << res;
	return 0;
}