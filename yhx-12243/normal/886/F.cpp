#include <bits/stdc++.h>
#define EB emplace_back
#define gcd std::__gcd
using std::cin;
using std::cout;

typedef long long ll;
typedef __int128 lll;
typedef std::pair <ll, ll> pr;
typedef std::vector <pr> vector;
typedef std::set <pr> set;
const int N = 2054;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	friend std::istream & operator >> (std::istream &in, vec2 &B) {return in >> B.x >> B.y;}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll operator * (const vec2 &B) const {return (ll)x * B.x + (ll)y * B.y;}
	inline ll operator ^ (const vec2 &B) const {return (ll)x * B.y - (ll)y * B.x;}
	inline ll norm2() const {return (ll)x * x + (ll)y * y;}
} p[N];

int n, cnt = 0;
bool alive[N];
vector cur, nxt, li;
lll pd[N];

inline void candidate(ll x, ll y) {
	assert(x || y);
	if (y < 0 || (!y && x < 0)) x = -x, y = -y;
	ll d = gcd(llabs(x), y); li.EB(x / d, y / d);
}

inline void tidy(vector &v) {std::sort(v.begin(), v.end()), v.erase(std::unique(v.begin(), v.end()), v.end());}

bool test(pr &vec) {
	ll x, y; std::tie(x, y) = vec;
	int i, j;
	for (i = 0; i < n; ++i) pd[i] = (lll)p[i].x * y - (lll)p[i].y * x;
	std::sort(pd, pd + n);
	for (i = 1, j = n - 2; i <= j; ++i, --j)
		if (pd[i] + pd[j] != pd[0] + pd[n - 1]) break;
	return i > j;
}

int main() {
	int i, j, k; ll Sx = 0, Sy = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> p[i], Sx += p[i].x, Sy += p[i].y;
	for (i = 0; i < n; ++i) alive[i] = (ll)n * p[i].x != Sx || (ll)n * p[i].y != Sy;
	for (i = 0; i < n; ++i)
		for (j = i + 1; alive[i] && j < n; ++j)
			if (ll(p[i].x + p[j].x) * n == Sx * 2 && ll(p[i].y + p[j].y) * n == Sy * 2)
				alive[i] = alive[j] = false;
	for (j = i = 0; i < n; ++i) if (alive[i]) p[j++] = p[i];
	if (!(n = j)) return cout << "-1\n", 0;
	assert(n > 1);
	for (Sx = Sy = i = 0; i < n; ++i) Sx += p[i].x, Sy += p[i].y;
	for (i = 0; i < n; ++i)
		candidate(n * ll(p->x + p[i].x) - Sx * 2, n * ll(p->y + p[i].y) - Sy * 2);
	nxt.swap(li), tidy(nxt);
	for (j = 0; j < 15; ++j) {
		k = rand() % n, li.clear(), cur.swap(nxt), nxt.clear();
		for (i = 0; i < n; ++i)
			candidate(n * ll(p[k].x + p[i].x) - Sx * 2, n * ll(p[k].y + p[i].y) - Sy * 2);
		tidy(li);
		std::set_intersection(cur.begin(), cur.end(), li.begin(), li.end(), std::back_inserter(nxt));
	}
	k = std::count_if(nxt.begin(), nxt.end(), test);
	if (k > 13) return -1;
	printf("%d\n", k);
	return 0;
}