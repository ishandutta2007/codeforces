#include <bits/stdc++.h>

typedef long long ll;
const int LEN = 540, N = 65536, LN = 16, mod = 1000000007;
typedef int vec[N], *pvec;

int n, buf[101];
int top = 0, stack[LEN];
char expression[LEN], *p = expression + 1;

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}

namespace Evaluator {
	int top = 0;
	vec _, B1, B2, stack[LEN];

	inline void init() {	
		buf[65] = 0xaaaa, buf[66] = 0xcccc, buf[67] = 0xf0f0, buf[68] = 0xff00;
		buf[97] = 0x5555, buf[98] = 0x3333, buf[99] = 0x0f0f, buf[100] = 0x00ff;
		for (int x : {65, 66, 67, 68, 97, 98, 99, 100}) ++_[buf[x]];
	}

	#define mobius(f, g) void f(pvec a) { \
			int i, j, k, len = 1; \
			for (i = 0; i < LN; ++i, len <<= 1) \
				for (j = 0; j < N; j += len << 1) \
					for (k = j; k < j + len; ++k) g; \
		}

	mobius(FMT1, add(a[k + len], a[k]))
	mobius(IFMT1, sub(a[k + len], a[k]))
	mobius(FMT2, add(a[k], a[k + len]))
	mobius(IFMT2, sub(a[k], a[k + len]))

	inline void and_conv(pvec a, pvec b) {FMT2(a), FMT2(b); for (int i = 0; i < N; ++i) a[i] = (ll)a[i] * b[i] % mod; IFMT2(a);}
	inline void or_conv(pvec a, pvec b) {FMT1(a), FMT1(b); for (int i = 0; i < N; ++i) a[i] = (ll)a[i] * b[i] % mod; IFMT1(a);}
	inline void full_conv(pvec a, pvec b) {memcpy(B1, a, sizeof(vec)), memcpy(B2, b, sizeof(vec)), and_conv(B1, B2), or_conv(a, b); for (int i = 0; i < N; ++i) add(a[i], B1[i]);}

	inline void insert(int op) {
		switch (op) {
			case -2: assert(top > 1), and_conv(stack[top - 2], stack[top - 1]), --top; break;
			case -3: assert(top > 1), or_conv(stack[top - 2], stack[top - 1]), --top; break;
			case -4: assert(top > 1), full_conv(stack[top - 2], stack[top - 1]), --top; break;
			case -5: memcpy(stack[top++], _, sizeof(vec)); break;
		}
		if (op > 0) memset(stack[top], 0, sizeof(vec)), stack[top++][op] = 1;
	}

	inline pvec current() {return stack[top - 1];}
}

int main() {
	int a, b, c, d, e, i, S, val[2] = {0, 0}, ans = 0; pvec res;
	Evaluator::init();
	for (scanf("%s%d", p, &n); *p; ++p)
		switch (*p) {
			case 40: stack[top++] = -1; break;
			case 41: for (a = 0; top && ~a; Evaluator::insert(a = stack[--top])); break;
			case 38: stack[top++] = -2; break;
			case 124: stack[top++] = -3; break;
			case 63: if (p[-1] == 41) stack[top++] = -4; else Evaluator::insert(-5); break;
			default: Evaluator::insert(buf[*p]); break;
		}
	for (; top; Evaluator::insert(stack[--top]));
	res = Evaluator::current();
	for (i = 0; i < n; ++i)
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e), val[e] |= 1 << (a | b << 1 | c << 2 | d << 3);
	if (*val & val[1]) return putchar(48), putchar(10), 0;
	i = S = (N - 1) & ~(*val | val[1]);
	do add(ans, res[ val[1] | i ]), i = (i - 1) & S; while (i != S);
	printf("%d\n", ans);
	return 0;
}