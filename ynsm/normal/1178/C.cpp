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

ll a, b, ans;
int main()
{
	cin >> a >> b;
	ans = 1;
	for(int i = 1; i <= a + b; i++)
		ans = ans * 2 % 998244353;
	cout << ans;
	return 0;
}