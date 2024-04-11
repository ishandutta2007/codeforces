#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define rg register
#define fu(i, a, b) for(rg int i = (a), I = (b) + 1; i < I; ++i)
inline int read() {
	int ret = 0;
	char op = getchar();
	while(op < '0' || op > '9') op = getchar();
	while(op >= '0' && op <= '9') ret = (ret << 3) + (ret << 1) + op - 48, op = getchar();
	return ret;
}

const int N = 100005;
int n, k, tot, id[N], prime[N], v[N];
ull w[N], ans; 
map<ull, int> mp;

inline void prework() {
	const int maxn = 100000;
	fu(i, 2, maxn) {
		if(!v[i]) {
			prime[++tot] = i;
			id[i] = tot;
			v[i] = i;
		}
		fu(j, 1, id[v[i]]) {
			if(i * prime[j] > maxn) break;
			v[i * prime[j]] = prime[j];
		}
	}
	fu(i, 1, tot) w[i] = 1ULL * rand() * rand() * rand() * rand();
}

inline void solve(int x) {
	ull xhash = 0, aimhash = 0;
	int ori = x;
	fu(i, 1, tot) {
		 if(prime[i] * prime[i] > ori) break;
		 int cnt = 0;
		 while(x % prime[i] == 0) ++cnt, x /= prime[i];
		 cnt %= k;
		 if(cnt) xhash += w[i] * cnt, aimhash += w[i] * (k - cnt);
	}
	if(x != 1) xhash += w[id[x]], aimhash += w[id[x]] * (k - 1);
	if(mp.count(aimhash)) ans += mp[aimhash];
	++mp[xhash];
}

int main() {
	srand(time(NULL));
	prework(); 
	n = read(), k = read();
	while(n--) solve(read());
	printf("%llu\n", ans);
	return 0;
}