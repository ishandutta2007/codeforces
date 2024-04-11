#include <bits/stdc++.h>

typedef long long ll;
const int N = 5054;

int n, si, ti;
int x[N], Ls[N], Rs[N], Lt[N], Rt[N];
std::priority_queue <ll, std::vector <ll>, std::greater <ll> > pq;

inline ll dist(int u, int v) {return u < v ? (ll)Rs[u] + Rt[v] : u > v ? (ll)Ls[u] + Lt[v] : 0;}

int main() {
	int i; ll ans, left_profit, right_profit;
	scanf("%d%d%d", &n, &si, &ti);
	for (i = 1; i <= n; ++i) scanf("%d", x + i);
	for (i = 1; i <= n; ++i) scanf("%d", Rt + i), Rt[i] += x[i];
	for (i = 1; i <= n; ++i) scanf("%d", Lt + i), Lt[i] -= x[i];
	for (i = 1; i <= n; ++i) scanf("%d", Ls + i), Ls[i] += x[i];
	for (i = 1; i <= n; ++i) scanf("%d", Rs + i), Rs[i] -= x[i];
	ans = dist(si, 1) + dist(1, ti);
	for (i = 2; i <= n; ++i) {
		left_profit = (ll)Rs[i] - Ls[i];
		right_profit = (ll)Lt[i] - Rt[i];
		if (i == si) pq.push(left_profit);
		else if (i == ti) pq.push(right_profit);
		else {
			if (i < si) pq.push(right_profit);
			if (i < ti) pq.push(left_profit);
			ans += pq.top() + Ls[i] + Rt[i], pq.pop();
			if (i > si) pq.push(right_profit);
			if (i > ti) pq.push(left_profit);
		}
	}
	printf("%lld\n", ans);
	return 0;
}