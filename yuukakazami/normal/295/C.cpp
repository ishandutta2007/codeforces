#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

typedef long long int64;

struct Int {
	int x;
	Int() :
			x(0) {
	}
	Int(int _x) :
			x(_x) {
		x %= MOD;
		if (x < 0)
			x += MOD;
	}
	Int(int64 _x) {
		x = _x % MOD;
		if (x < 0)
			x += MOD;
	}
	static Int get(int x) {
		Int a;
		a.x = x;
		return a;
	}

	Int operator+(const Int&o) const {
		int t = x + o.x;
		if (t >= MOD)
			t -= MOD;
		return get(t);
	}
	Int operator*(const Int&o) const {
		return get(1LL * x * o.x % MOD);
	}
	Int operator-(const Int&o) const {
		int t = x - o.x;
		if (t < 0)
			t += MOD;
		return get(t);
	}
	Int operator/(const Int&o) const {
		return (*this) * o.inv();
	}
	Int&operator+=(const Int&o) {
		return (*this) = *this + o;
	}
	Int&operator-=(const Int&o) {
		return (*this) = *this - o;
	}
	Int&operator*=(const Int&o) {
		return (*this) = *this * o;
	}
	Int&operator/=(const Int&o) {
		return (*this) = *this / o;
	}

	Int power(int64 n) const {
		if (!n)
			return get(1);
		const Int&a = *this;
		if (n & 1)
			return power(n - 1) * a;
		else
			return (a * a).power(n >> 1);
	}

	Int inv() const {
		return power(MOD - 2);
	}
};

const int MAX_N = 50 + 10;
const int INF = ~0U >> 2;

struct Result {
	int move;
	Int way;
	Result(int move, Int way) :
			move(move), way(way) {
	}

	Result() {
		move = INF;
		way = 0;
	}
};

Int dp[MAX_N][MAX_N][2]; //left : a,b right n50-a,n100-b

Int comb[MAX_N][MAX_N];

int n, k;
int cnt1, cnt2;

struct State {
	int a, b; //left:a,b
	int at; //goat loc
	State(int a, int b, int at) :
			a(a), b(b), at(at) {
	}
};

bool used[MAX_N][MAX_N][2], in[MAX_N][MAX_N][2];

vector<State> cur, nxt;

void add(int a, int b, int at, Int way) {
	if (used[a][b][at] && !in[a][b][at])
		return;
	if (!used[a][b][at])
		nxt.push_back(State(a, b, at));
	in[a][b][at] = used[a][b][at] = true;
	dp[a][b][at] += way;
}

int main() {
	cin >> n >> k;
	k /= 50;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x == 50)
			++cnt1;
		else
			++cnt2;
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			comb[i][j] =
					(i == 0 || j == 0) ?
							1 : comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}

	nxt.push_back(State(cnt1, cnt2, 0));
	dp[cnt1][cnt2][0] = 1;
	used[cnt1][cnt2][0] = true;

	int dist = 0;

	while (!nxt.empty()) {
		cur = nxt;
		nxt.clear();

		memset(in, 0, sizeof in);

		for (int i = 0; i < (int) cur.size(); ++i) {
			State st = cur[i];
			//move!
			int a = st.a, b = st.b, at = st.at;
			Int c = dp[a][b][at];

			if (at == 0) { //I'm left
				for (int x = 0; x <= a; ++x) {
					for (int y = 0; y <= b && x + 2 * y <= k; ++y) {
						if (x + y > 0)
							add(a - x, b - y, 1, c * comb[a][x] * comb[b][y]);
					}
				}
			} else {
				a = cnt1 - a, b = cnt2 - b;
				for (int x = 0; x <= a; ++x) {
					for (int y = 0; y <= b && x + 2 * y <= k; ++y) {
						if (x + y > 0)
							add(cnt1 - (a - x), cnt2 - (b - y), 0,
									c * comb[a][x] * comb[b][y]);
					}
				}
			}
		}

		++dist;
		if (in[0][0][1]) {
			cout << dist << endl;
			cout << dp[0][0][1].x << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	cout << 0 << endl;
	return 0;
}