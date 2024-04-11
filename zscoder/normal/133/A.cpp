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
	string s; cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
		{
		cout << "YES"; return 0;
	}
}
cout << "NO";
	return 0;
}