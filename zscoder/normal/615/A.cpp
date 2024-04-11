#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll lINF = ll(1e18);
bool open[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int s, x;
	fill(open, false);
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		for(int j = 0; j < s; j++)
		{
			cin >> x;
			open[x-1] = true;
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(open[i] == false)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}

/*B
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

/*C
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

/*D
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/

/*E
int main()
{
	ios_base::sync_with_stdio(false);
	
	return 0;
}
*/