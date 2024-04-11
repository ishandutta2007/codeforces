#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;


#define Seg_Max_N (1<<18) 
const int dummy = 100000000;
pair<int,int> dat[2 * Seg_Max_N][2];
struct segtree {
	int N;
	segtree() {}
	segtree(int n) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i][0] = make_pair(-1,0);
			dat[i][1] = make_pair(-1, 0);
		}
	}
	// update k th element
	void update(int k, int a) {
		k += N - 1; // leaf
		dat[k][0] = make_pair(a, k-N+1);
		while (k > 0) {
			k = (k - 1) / 2;
			pair<int, int> al0(dat[k * 2 + 1][0]);
			pair<int, int> al1(dat[k * 2 + 1][1]);
			pair<int, int> ar0(dat[k * 2 + 2][0]);
			pair<int, int> ar1(dat[k * 2 + 2][1]);
			if (al1.first!=-1) {
				dat[k][0] =al0;
				dat[k][1] = al1;
			}
			else if (al0.first != -1) {
				if (ar0.first != -1 && ar0.first != al0.first) {
					dat[k][0] = al0;
					dat[k][1] = ar0;
				}else if (ar1.first != -1 && ar1.first != al0.first) {
					dat[k][0] = al0;
					dat[k][1] = ar1;
				}
				else {
					dat[k][0] = al0;
					dat[k][1] = make_pair(-1,0);
				}
			}
			else {
				dat[k][0] = ar0;
				dat[k][1] = ar1;
			}
		}
	}
	// min [a, b)
	int query(int a, int b,int n) { return query(a, b,n, 0, 0, N); }
	int query(int a, int b,int n, int k, int l, int r) {
		if (r <= a or b <= l) return dummy;
		if (a <= l and r <= b) {
			for (int i = 0; i < 2; ++i) {
				if (dat[k][i].first != n&&dat[k][i].first != -1) {
					return dat[k][i].second;
				}
			}
			return dummy;
		}
		const int m = (l + r) / 2;
		const int al(query(a, b,n, k * 2 + 1, l, m));
		if (al == dummy) {
			const int ar(query(a, b, n, k * 2 + 2, m, r));
			return ar;
		}else{
			return al;
		}
	}
};

int main() {
	int N, M; cin >> N >> M;
	segtree seg(N);
	for (int i = 0; i < N; ++i) {
		int a; 
		scanf("%d", &a);
		seg.update(i, a);
	}
	for (int i = 0; i < M; ++i) {
		int l, r, x; scanf("%d%d%d", &l, &r, &x);
		l--;
		int ans = seg.query(l, r, x);
		if (ans == dummy)ans = -2;
		cout << ans+1 << endl;
	}
	return 0;
}