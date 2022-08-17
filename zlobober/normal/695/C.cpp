#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define mt make_tuple
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define next hunext
#define rank hurank
#define prev huprev
#define link hulink
#define hash huhash
#define y0 yy0
#define y1 yy1
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (false) cerr
#endif

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;
typedef long double ldouble;

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;

struct vt {
	llong x, y;
	vt(llong _x, llong _y) {
		x = _x, y = _y;
	}
	friend vt operator -(vt a, vt b) {
		return vt(a.x - b.x, a.y - b.y);
	}
	friend vt operator +(vt a, vt b) {
		return vt(a.x + b.x, a.y + b.y);
	}
	friend llong operator *(vt a, vt b) {
		return a.x * b.x + a.y * b.y;
	}
	friend llong operator ^(vt a, vt b) {
		return a.x * b.y - b.x * a.y;
	}
	int halfplane() {
		assert((x != 0) || (y != 0));
		return (y < 0 || (y == 0 && x < 0));
	}
	vt() {}
};

const int N = 1050;
const int K = 10;
vt P[K];
vt Q[N];

bool bad[K][N];
vector<int> between[K][N];

struct Comp {
	vt O;
	Comp(vt _O) {
		O = _O;
	}
	bool operator ()(int a, int b) {
		vt A = Q[a] - O;
		vt B = Q[b] - O;
		if (A.halfplane() != B.halfplane())
			return A.halfplane() < B.halfplane();
		else {
			llong vp = (A ^ B);
			if (vp != 0)
				return vp > 0;
			else
				return A * A < B * B;
		} 
	}
};

int in_need[N];

bool go(const vector<int>& rem_P, const vector<int>& need_Q) {
	if (rem_P.size() < need_Q.size())
		return false;
	if (need_Q.empty())
		return true;
	vector<int> new_need_Q, new_rem_P;
	for (int i : rem_P) {
		for (int j : need_Q) {
			if (bad[i][j])
				continue;
			new_need_Q = need_Q;
			new_need_Q.erase(find(new_need_Q.begin(), new_need_Q.end(), j));
			in_need[j]--;
			for (int x : between[i][j]) {
				in_need[x]++;
				if (in_need[x] == 1)
					new_need_Q.push_back(x);
			}
			bool ret_true = false;
			if (new_need_Q.size() <= (int)rem_P.size() - 1) {
				new_rem_P.clear();
				for (int y : rem_P) {
					if (y != i) {
						new_rem_P.push_back(y);
					}
				}
				assert((int)new_rem_P.size() == (int)rem_P.size() - 1);
				if (go(new_rem_P, new_need_Q)) {
					ret_true = true;
				}
			}
			for (int x : between[i][j]) {
				in_need[x]--;
			}
			in_need[j]++;
			if (ret_true)
				return true;
		}
	}
	return false;
}

int main() {
#define TASK "C"
#ifdef LOCAL42
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
#else

#endif

	int k, n;
	scanf("%d %d", &k, &n);
	//n = 1000;
	//k = 7;
	for (int i = 0; i < k; i++) {
		cin >> P[i].x >> P[i].y;
		//P[i] = vt(rand() % 10000, 0);
	}
	for (int i = 0; i < n; i++) {
		cin >> Q[i].x >> Q[i].y;
		//Q[i] = vt(rand() % 10000, 0);
	}

	for (int i = 0; i < k; i++) {
		vector<int> ind;
		for (int j = 0; j < n; j++) {
			ind.push_back(j);
		}
		
		auto comp = Comp(P[i]); 
		sort(ind.begin(), ind.end(), comp);
		
		for (int l = 0, r = 0; l < n; ) {
			while (r < n && ((((Q[ind[r]] - P[i]) ^ (Q[ind[l]] - P[i])) == 0) && (((Q[ind[r]] - P[i]) * (Q[ind[l]] - P[i])) > 0))) {
				r++;
			}
			vector<int> cur_between;
			for (int q = l; q < r; q++) {
				if (cur_between.size() >= k)
					bad[i][ind[q]] = true;
				else 
					between[i][ind[q]] = cur_between;
				cur_between.push_back(ind[q]);
			}
			l = r;
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		vector<int> rem_P, need_Q = { i };
		for (int j = 0; j < k; j++) {
			rem_P.push_back(j);
		}
		if (go(rem_P, need_Q)) {
			++ans;
			eprintf("%d\n", i);
		}
	}
	printf("%d\n", ans);

	return 0;
}