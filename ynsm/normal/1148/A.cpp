#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

ll a, b, c, ans;
int main()
{
	cin >> a >> b >> c;               
	ans = max(ans, c * 2 + min(a, b) * 2 + (a > b));
	b--;
	ans = max(ans, c * 2 + min(a, b) * 2 + (a > b) + 1);
	cout << ans;
	return 0;
}