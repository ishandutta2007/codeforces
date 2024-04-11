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
	int b, g, n;
	int ans = 0;
	cin >> b >> g >> n;
	for(int i = 0; i <= b; i++)
		for(int j = 0; j <= g; j++)
			if(i + j == n)
				ans++;
	cout << ans;
	return 0;
}