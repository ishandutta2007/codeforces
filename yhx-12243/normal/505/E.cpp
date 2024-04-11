#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pr; 

const int N = 100054;

int n, rounds, each, delta;
int a[N];
ll h[N], height[N];
std::priority_queue <pr, std::vector <pr>, std::greater <pr> > pq;

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}

inline bool check(ll limit) {
	int i, r, cur; pr t;
	for (; !pq.empty(); pq.pop());
	std::fill(height, height + n, limit);
	for (i = 0; i < n; ++i) if (height[i] < h[i]) pq.emplace(height[i] / a[i], i);
	for (r = 1; r <= rounds && !pq.empty(); ++r)
		for (cur = each; cur && !pq.empty(); --cur) {
			t = pq.top(), pq.pop(), i = t.second;
			if (r > t.first) return false;
			if ((height[i] += delta) < h[i]) pq.emplace(height[i] / a[i], i);
		}
	return pq.empty();
}

int main() {
	int i; ll L = 0, R = 0, M;
	scanf("%d%d%d%d", &n, &rounds, &each, &delta);
	for (i = 0; i < n; ++i)
		scanf("%lld%d", h + i, a + i), up(R, h[i] += (ll)a[i] * rounds);
	for (; L < R; M = (L + R) / 2, check(M) ? R = M : (L = M + 1));
	printf("%lld\n", L);
	return 0;
}