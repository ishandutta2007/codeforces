#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	int ans = n;
	b *= 5;
	for(int i = 0; i * a <= n; i++)
		ans = min(ans, (n - i * a) % b);
	cout << ans;
	return 0;
}