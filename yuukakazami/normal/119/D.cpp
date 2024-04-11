#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
string A, B;

const int SEED = 133331;
typedef long long int64;

struct Hash {
	vector<int64> pow, h;
	Hash(string s) {
		int n = s.size();
		h.resize(n + 1);
		pow.resize(n + 1);
		h[0] = 0;
		pow[0] = 1;
		for (int i = 0; i < n; ++i) {
			h[i + 1] = h[i] * SEED + s[i];
			pow[i + 1] = pow[i] * SEED;
		}
	}
	int64 ask(int l, int r) const { //[l,r)
		return h[r] - h[l] * pow[r - l];
	}
};

int n;

int getLcp(const Hash&a, int ia, const Hash&b, int ib) {
	int left = 0, right = n + 1;
	while (left + 1 < right) {
		int m = left + right >> 1;
		if (ia + m <= n && ib + m <= n) {
			if (a.ask(ia, ia + m) == b.ask(ib, ib + m)) {
				left = m;
				continue;
			}
		}
		right = m;
	}
	return left;
}

struct Tree {
	Tree*pl, *pr;
	int l, m, r, v;
	inline int get(int a, int b) {
		return max(a, b);
	}
	void update() {
		v = get(pl->v, pr->v);
	}
	Tree(const vector<int>&seq, int _l, int _r) :
			l(_l), r(_r) {
		m = (l + r) >> 1;
		if (l + 1 == r) {
			pl = pr = 0;
			v = seq[l];
			return;
		}
		pl = new Tree(seq, l, m);
		pr = new Tree(seq, m, r);
		update();
	}
	int find(int L, int R, int need) {
		if (L >= r || l >= R)
			return -1;
		if (L <= l && R >= r) {
			if (v >= need) {
				if (l + 1 == r)
					return l;
				int a = pl->find(L, R, need);
				if (a == -1)
					return pr->find(L, R, need);
				else
					return a;
			} else {
				return -1;
			}
		}
		int a = pl->find(L, R, need);
		if (a == -1)
			return pr->find(L, R, need);
		else
			return a;
	}
};

int main() {
	getline(cin, A);
	getline(cin, B);
	if (A.size() != B.size()) {
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	string rA = A, rB = B;
	reverse(rA.begin(), rA.end());
	reverse(rB.begin(), rB.end());
	Hash a(A), ra(rA), b(B), rb(rB);
	int maxI = 0;
	n = A.size();
	for (int i = 0; i < n; ++i) {
		if (A[i] == B[n - 1 - i]) {
			maxI++;
		} else
			break;
	}
	if (maxI == n)
		maxI--;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = getLcp(b, i, ra, 0) + i;
	}
	Tree*rt = new Tree(v, 0, n);
	for (int i = maxI - 1; i >= 0; --i) {
		int lcp = getLcp(a, i + 1, b, 0);
		int rem = n - 1 - i;
		int j = rt->find(0, lcp + 1, rem);
		if (j != -1) {
			cout << i << " " << i + j + 1 << endl;
			return 0;
		}
	}
	cout << -1 << " " << -1 << endl;
	return 0;
}