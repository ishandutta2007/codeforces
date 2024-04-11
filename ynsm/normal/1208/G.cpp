#include <bits/stdc++.h>

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

int n, k, ld[N], f[N];
ll ans;
int main()
{
	cin >> n >> k;
	if(k == 1){
		cout << 3;
		return 0;
	}
	for(int i = 2; i <= n; i++)
		if(ld[i] == 0)
			for(int j = i; j <= n; j += i)
				ld[j] = i;
	k += 2;
	f[1] = 1;
	for(int i = 2; i <= n; i++){
		int x = i, y = 1, p = ld[i];
		while(x % p == 0)
			x /= p, y *= p;
		f[i] = y / p * (p - 1) * f[x];
	}
	sort(f + 1, f + 1 + n);     
	for(int i = 1; i <= k; i++)
		ans += f[i];
	cout << ans;
	return 0;
}