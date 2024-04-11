#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
const int inv2 = (P + 1) / 2;
const int K = 60;
vector<pair<long long, long long>> segs;
struct DS {
	int n;	
	vector<long long> b1[K + 1], b2[K + 1];
	void insert(int k, long long l, long long r, long long ll, long long rr) {
		b1[k].emplace_back(l);
		if (l >= ll && r <= rr) {
			b2[k].emplace_back(l);
			return;
		}
		long long mid = (l + r) >> 1;
		if (mid >= ll) 
			insert(k - 1, l, mid, ll, rr);
		if (mid < rr) 
			insert(k - 1, mid + 1, r, ll, rr);
	}
	void init() {
		scanf("%d", &n);
		while (n--) {
			long long l, r;
			scanf("%lld%lld", &l, &r);
			insert(K, 0, (1ll << K) - 1, l, r);
		}
	}
} A, B;
void solve(const DS &A, const DS &B) {
	for (int k = K - 1; ~k; --k) {
		long long len = 1ll << k;
		for (auto l1 : A.b2[k]) {
			for (auto l2 : B.b1[k]) {
				long long l = l1 ^ l2;
				segs.emplace_back(l, l + len - 1);
			}
		}
	}
}
int calc(long long l, long long r) {
	int ans = (l + r) % P;
	ans = (r - l + 1) % P * ans % P;
	return 1ll * ans * inv2 % P;
}
int main() {
	A.init(), B.init();
	solve(A, B);
	solve(B, A);
	sort(segs.begin(), segs.end());
	int ans = 0;
	long long maxr = -1;
	for (auto p : segs) {
		if (p.second > maxr) {
			ans = (ans + calc(max(p.first, maxr + 1), p.second)) % P;
			maxr = p.second;
		}
	}
	printf("%d\n", ans);
	return 0;
}