#include <bits/stdc++.h>
#define lg2 std::__lg
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 400054;

int n, m, V, root;
bool det[N];
pr v[N];

std::istream & operator >> (std::istream &in, pr &B) {return in >> B.first >> B.second;}

inline int max(const int x, const int y) {return x < y ? y : x;}
inline int clean(int x, int y) {return y ? x & (-2 << lg2(y)) : x;}
inline int depth(const pr &A) {return A.first | A.second;}

inline bool cmp(const pr &A, const pr &B) {
	int w = max(A.first ^ B.first, A.second ^ B.second), aZ, bZ;
	if (!w) return false;
	w = lg2(w), aZ = (A.second >> w & 1) - (A.first >> w & 1), bZ = (B.second >> w & 1) - (B.first >> w & 1);
	if (!aZ && !(A.second & ~(-2 << w))) aZ = -2;
	if (!bZ && !(B.second & ~(-2 << w))) bZ = -2;
	return aZ < bZ;
}

inline pr LCA(const pr &A, const pr &B) {
	int w = max(A.first ^ B.first, A.second ^ B.second), aX, aY, bX, bY, cX, cY;
	if (!w) return A;
	w = lg2(w),
	cX = A.first & (-2 << w), cY = A.second & (-2 << w),
	aX = A.first & ~(-2 << w), aY = A.second & ~(-2 << w),
	bX = B.first & ~(-2 << w), bY = B.second & ~(-2 << w);
	if (((aX | aY) & (bX | bY)) >> w & 1) return pr(cX, cY);
	if (aX >> w & 1) return pr(cX + clean(bX, bY), cY);
	if (aY >> w & 1) return pr(cX, cY + clean(bY, bX));
	if (bX >> w & 1) return pr(cX + clean(aX, aY), cY);
	if (bY >> w & 1) return pr(cX, cY + clean(aY, aX));
	throw "gg";
}

namespace DC {
	struct node {
		pr v; int id;
		inline bool operator < (const node &B) {return cmp(v, B.v);}
	} D[N];
	int F[N];

	int Discretize(int n) {
		int i, cnt = 0; std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].id] = (i && D[i].v == D[i - 1].v ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

namespace tree {
	int p[N], fc[N], nc[N];
	int w[N];
	std::map <int, int> pool;

	inline void link(int x, int px) {nc[x] = fc[px], fc[px] = x;}

	void DSA() {	
		#define ins(x) (p[x] = stack[top], stack[++top] = x)
		int i, x, y, top = 0; pr t; V = n;
		static int stack[N];
		memset(stack, -1, sizeof stack);
		for (i = 0; i < n; ++i)
			if (x = i, !top) ins(x);
			else {
				stack[top + 1] = -1, t = LCA(v[x], v[stack[top]]);
				for (; depth(v[stack[top]]) > depth(t); --top);
				if (top && v[stack[top]] == t) y = stack[top];
				else v[y = V++] = t;
				if (~stack[top + 1]) p[ stack[top + 1] ] = y;
				if (stack[top] != y) ins(y); ins(x);
			}
		root = stack[1];
	}

	void dfs(int x) {
		int y, s = 0;
		for (y = fc[x]; ~y; y = nc[y]) dfs(y), w[x] += w[y], s += w[y];
		if (w[x])
			assert(x != root), ++pool[depth(v[p[x]]) + 1];
		else if (s || det[x])
			++pool[depth(v[x])];
		else return;
		--pool[depth(v[x]) + 1];
	}

	int main() {
		int i, ret = 0;
		memset(fc, -1, sizeof fc);
		for (i = 0; i < V; ++i) if (~p[i]) link(i, p[i]);
		dfs(root);
		for (const pr &e : pool) if (e.second & 1) ret += (bool)e.first;
		return ret;
	}
}

int main() {
	int i, a, b, c;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> m;
	for (i = 0; i < m; ++i) cin >> DC::D[i].v >> DC::D[i + m].v, DC::D[i + 2 * m].v = LCA(DC::D[i].v, DC::D[i + m].v);
	for (i = 0; i < 3 * m; ++i) DC::D[i].id = i;
	n = DC::Discretize(3 * m);
	for (i = 0; i < n; ++i) v[i] = DC::D[i].v;
	tree::DSA();
	for (i = 0; i < m; ++i) {
		a = DC::F[i], b = DC::F[i + m], c = DC::F[i + 2 * m], ++tree::w[a], ++tree::w[b], tree::w[c] -= 2;
		if (a == b) det[a] = true;
	}
	cout << tree::main() << '\n';
	return 0;
}