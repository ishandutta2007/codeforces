#include <bits/stdc++.h>

typedef std::pair <int, int> edge;
const int N = 100054;

int V, E;
int p[N];
edge e[N];
bool b[N];

inline bool exist_edge(int u, int v) {return std::binary_search <edge*, edge> (e, e + E, std::minmax(u, v));}

int main() {
	int i, u, v, amount, T;
	char *_ = new char; std::mt19937 gen(time(NULL) + (unsigned long long)_); delete _;
	scanf("%d%d", &V, &E);
	for (i = 0; i < E; ++i) scanf("%d%d", &u, &v), e[i] = std::minmax(u, v);
	std::sort(e, e + E), std::iota(p, p + V, 1);
	for (T = (V < 6 ? 1254 : INT_MAX); T; --T) {
		std::shuffle(p, p + V, gen), p[V] = *p;
		for (amount = i = 0; i < V; ++i) amount += b[i] = !exist_edge(p[i], p[i + 1]);
		if (amount >= E) {
			for (i = 0; i < V && E; ++i) E -= b[i] && printf("%d %d\n", p[i], p[i + 1]);
			return 0;
		}
	}
	return puts("-1"), 0;
}