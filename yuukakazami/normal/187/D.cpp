#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;
typedef long long int64;
int n, g, r, nQ, tot;
const int MAX_N = int(1e5) + 10;
int64 l[MAX_N];

template<class T>
struct Index: public vector<T> {
	using vector<T>::erase;
	using vector<T>::begin;
	using vector<T>::end;
	void doit() {
		sort(begin(), end());
		erase(unique(begin(), end()), end());
	}
	int get(T x) {
		return lower_bound(begin(), end(), x) - begin();
	}
};

const int INF = ~0U >> 2;

Index<int> idx;

struct Tree {
	Tree*pl, *pr;
	int l, r, vl, vr;
	int minv;

	void update() {
		minv = min(pl->minv, pr->minv);
	}

	Tree(int l, int r) :
			l(l), r(r), minv(n) {
		vl = idx[l], vr = idx[r - 1];
		if (l + 1 == r) {
			return;
		}
		pl = new Tree(l, l + r >> 1);
		pr = new Tree(l + r >> 1, r);
		update();
	}

	int query(int L, int R) { //[L,R]
		//[vL,vR]
		if (L > R)
			return n;
		if (L > vr || vl > R)
			return n;
		if (L <= vl && R >= vr) {
			return minv;
		}
		return min(pl->query(L, R), pr->query(L, R));
	}

	void change(int i, int x) {
		if (i < l || i >= r)
			return;
		if (l + 1 == r) {
			minv = min(minv, x);
			return;
		}
		pl->change(i, x);
		pr->change(i, x);
		update();
	}
}*root;

int calc(int64 at, int t) { //nxt stop
	//what is the first l[i]>at && (l[i]-at+t)%(g+r)>=g
	//first l[i]%(g+r) belong to some interval
	int d = (-at % tot + t + tot) % tot;
	//(l[i]+d)%tot>=g // g<=l[i]+d<tot g-d<=l[i]<tot-d
	if (g - d >= 0) {
		return root->query(g - d, tot - d - 1);
	} else {
		return min(root->query(0, tot - d - 1), root->query(g - d + tot, tot - 1));
	}
}

int64 dp[MAX_N];

int main() {
	cin >> n >> g >> r;
	tot = g + r;
	for (int i = 0; i <= n; ++i) {
		cin >> l[i];
		if (i > 0)
			l[i] += l[i - 1];
		idx.push_back(l[i] % tot);
	}
	idx.doit();
	root = new Tree(0, idx.size());
	dp[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		int t = calc(l[i], 0);
		if (t < n) {
			dp[i] = l[t] - l[i] + dp[t] + (tot - (l[t] - l[i]) % tot);
		} else
			dp[i] = l[t] - l[i];
		root->change(idx.get(l[i] % tot), i);
	}
	int nQ;
	cin >> nQ;
	for (int i = 0; i < nQ; ++i) {
		int t;
		cin >> t;
		int nxt = calc(0, t);
		int64 ans;
		if (nxt < n) {
			int64 when = t + l[nxt], wait = tot - when % tot;
			ans = t + l[nxt] + dp[nxt] + wait;
		} else {
			ans = t + l[nxt];
		}
		cout << ans << endl;
	}
	return 0;
}