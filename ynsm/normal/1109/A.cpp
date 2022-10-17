#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, pre[N], cnt[2][N];
ll ans;
int main()
{
	scanf("%d", &n);
	cnt[0][0]++;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		pre[i] = pre[i - 1] ^ x;
		ans += cnt[i & 1][pre[i]];
		cnt[i & 1][pre[i]]++;
	}
	printf("%lld", ans);
	return 0;
}