#include <bits/stdc++.h>
#define EB emplace_back
#define dot(x, y, z) (((y) - (x)) * ((z) - (x)))
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 1054;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	vec2 * read() {scanf("%d%d", &x, &y); return this;}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline int operator * (const vec2 &B) const {return x * B.x + y * B.y;}
	inline int operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
	inline int norm2() const {return x * x + y * y;}
	inline bool operator < (const vec2 &B) const {return x < B.x || (x == B.x && y < B.y);}
	inline bool operator == (const vec2 &B) const {return x == B.x && y == B.y;}
} p[N];

int n, CH;
int ch[N], o[N];
bool col[N];
std::vector <pr> edges;

inline void link(int x, int y) {edges.EB(std::minmax(x, y));}

int graham(int *dest) {
	int i, *ret = dest;
	std::iota(o, o + n, 0);
	std::iter_swap(o, std::min_element(o, o + n, [] (const int x, const int y) {return p[x] < p[y];}));
	std::sort(o + 1, o + n, [] (const int x, const int y) {return cross(p[*o], p[x], p[y]) > 0;});
	for (i = 0; i < n; *ret++ = o[i++])
		for (; ret > dest + 1 && cross(p[ret[-2]], p[o[i]], p[ret[-1]]) >= 0; --ret);
	return *ret = *o, ret - dest;
}

inline bool in_triangle(int P, int A, int B, int C) {
	int AB = cross(p[P], p[A], p[B]), BC = cross(p[P], p[B], p[C]), CA = cross(p[P], p[C], p[A]);
	return AB && BC && CA && (AB ^ BC) >= 0 && (AB ^ CA) >= 0;
}

void recursion(int A, int B, int C) {
	bool mode = !((col[A] && (col[B] || col[C])) || (col[B] && col[C]));
	if (col[B] == mode) std::swap(A, B);
	if (col[C] == mode) std::swap(A, C);
	int i; assert(col[A] == mode && col[B] == !mode && col[C] == !mode);
	for (i = 0; i < n; ++i)
		if (in_triangle(i, A, B, C) && col[i] == mode) {
			link(A, i), recursion(A, B, i), recursion(B, C, i), recursion(C, A, i); return;
		}
	for (i = 0; i < n; ++i) if (in_triangle(i, A, B, C)) link(B, i);
}

int main() {
	int i, j, L1, L2; bool outer;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) p[i].read(), scanf("%d", &j), col[i] = j;
	CH = graham(ch), outer = col[*ch];
	for (i = 0; i < CH && col[ ch[i] ] == outer; ++i);
	if (i == CH) {
		for (j = 0; j < n && col[j] == outer; ++j);
		if (j == n)
			for (i = 1; i < n; ++i) link(0, i);
		else {
			for (i = 1; i < CH; ++i) link(ch[i - 1], ch[i]), recursion(ch[i - 1], ch[i], j);
			recursion(ch[CH - 1], *ch, j);
		}
	} else {
		for (L1 = i; i < CH && col[ ch[i] ] == !outer; ++i);
		for (L2 = i; i < CH && col[ ch[i] ] == outer; ++i);
		if (i != CH) return puts("Impossible"), 0;
		for (i = 1; i <= CH; ++i) if (col[ ch[i - 1] ] == col[ ch[i] ]) link(ch[i - 1], ch[i]);
		for (i = L1; i < L2 - 1; ++i) recursion(ch[L1 - 1], ch[i], ch[i + 1]);
		for (i = L2; i < CH; ++i) recursion(ch[L2 - 1], ch[i], ch[i + 1]);
		for (i = 0; i < L1 - 1; ++i) recursion(ch[L2 - 1], ch[i], ch[i + 1]);
	}
	std::sort(edges.begin(), edges.end());
	printf("%d\n", (int)edges.size());
	for (const pr &e : edges) printf("%d %d\n", e.first, e.second);
	return 0;
}