#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int>> g[100005];
vector<pair<int, long long>> events[100005];
struct DS {
	map<int, long long> pos, neg;
	priority_queue<pair<int, int>> pq;
	int offset;
	inline void push(int x, long long y, bool is_ins = true) {
		if (y >= 0) {
			if (is_ins) {
				x += offset; 
				pos[x] += y;
			} else {
				pos[x] = y;
			}
			auto it = neg.upper_bound(x - offset * 2);
			if (it != neg.begin()) pq.emplace(-(x - (--it)->first), x);
		} else {
			if (is_ins) {
				x -= offset;
				neg[x] += y;
			} else {
				neg[x] = y;
			}
			auto it = pos.lower_bound(x + offset * 2);
			if (it != pos.end()) pq.emplace(-(it->first - x), it->first); 
		}
	}
	inline void expand(int d) {
		while (!pq.empty()) {
			auto p = pq.top();
			if (-p.first > 2 * (offset + d)) break;
			pq.pop();
			int p1 = p.second;
			if (!pos.count(p1)) continue;
			long long val = pos[p1];
			int p2 = p1 + p.first;
			if (!neg.count(p2)) continue;
			val += neg[p2];
			if (val >= 0) {
				neg.erase(p2);
				push(p1, val, false);				
			} else {
				pos.erase(p1);
				push(p2, val, false);
			}
		}
		offset += d;
	}
	inline long long get_max() {
		long long ans = 0, sum = 0;
		auto ptr = neg.begin();
		for (auto p : pos) {
			while (ptr != neg.end() && ptr->first + offset < p.first - offset)	
				sum += ptr->second, ++ptr;
			sum += p.second;
			ans = max(ans, sum);
		}
		return ans;
	}
	inline int get_size() {
		return int(pos.size() + neg.size());
	}
	inline void operator+=(const DS &rhs) {
		for (auto p : rhs.pos) 
			push(p.first - rhs.offset, p.second);
		for (auto p : rhs.neg) 
			push(p.first + rhs.offset, p.second);
	}
	inline long long get1(int x) {
		long long ans = 0;
		if (pos.count(x + offset)) ans += pos[x + offset];
		if (neg.count(x - offset)) ans += neg[x - offset];
		return ans;
	}
	inline long long get(int x) {
		long long l = 0, m = l + get1(x), r = m + get1(x + 1);
		return max(max(l, r), m) - m;
	}
	void debug() {
		printf("val = %lld\n", get_max());
		for (auto p : pos)
			printf("add::%d %lld\n", p.first - offset, p.second);
		for (auto p : neg)
			printf("sub::%d %lld\n", p.first + offset, p.second);
	}
} S[100005];
void dfs(int u, int fa) {
	for (auto p : g[u]) {
		int v = p.first, w = p.second;
		if (v == fa) continue;
		dfs(v, u);
		for (auto &it : events[v])
			it.second -= S[v].get(it.first);
		S[v].expand(1);
		for (auto it : events[v]) {
			if (it.second < 0) continue;
			S[v].push(it.first, it.second);
			S[v].push(it.first + 1, -it.second);
		}
		S[v].expand(w - 1);
		if (S[u].get_size() < S[v].get_size()) swap(S[u], S[v]);
		S[u] += S[v];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].emplace_back(v, w * 2);
		g[v].emplace_back(u, w * 2);
	}
	g[0].emplace_back(1, 2);
	scanf("%d", &k);
	while (k--) {
		int d, f, u;
		scanf("%d%d%d", &d, &f, &u);
		events[u].emplace_back(d * 2, f);
	}
	dfs(0, 0);
	printf("%lld\n", S[0].get_max());
	return 0;
}