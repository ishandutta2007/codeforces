#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((ll) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
	vector<string> names = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

	int a; string s;
	cin >> a >> s;

	for (string& o : names) if (o.length() == a)
	{
		bool ok = true;
		loop(i, a)
		{
			if (s[i] != '.' && s[i] != o[i])
				ok = false;
		}
		if (ok)
			cout << o << endl;
	}
}