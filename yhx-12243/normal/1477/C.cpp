#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 5054;

struct vec2 {
	int x, y;
	vec2 (int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
	friend std::istream & operator >> (std::istream &in, vec2 &B) {return in >> B.x >> B.y;}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline ll norm2() const {return (ll)x * x + (ll)y * y;}
} p[N];

int n;
int c[N];
bool used[N];

void work() {
	int i, j, k, la = 0;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> p[i], used[i] = false;
	*c = 0, *used = true;
	for (i = 1; i < n; ++i) {
		k = la;
		for (j = 0; j < n; ++j)
			if (!used[j] && (p[la] - p[j]).norm2() > (p[la] - p[k]).norm2())
				k = j;
		la = c[i] = k, used[k] = true;
	}
	for (i = 0; i < n; ++i) cout << c[i] + 1 << (i == n - 1 ? '\n' : ' ');
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	work();
	return 0;
}