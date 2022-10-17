#include <bits/stdc++.h>
using namespace std;
inline void down(int &x, int y) {
	x > y ? x = y : 0;
}
int n, q;
char s[100005];
int ID(int a, int b, int c) {
	return a * 6 + b * 2 + c;
} 
struct trans {
	int a, b, c;
};
vector<trans> tr;
struct node {
	int val[18];
	node() { memset(val, 0x3f, sizeof val); }
	inline node operator+(const node &rhs) const {
		node res;
		for (auto p : tr) {
			down(res.val[p.c], val[p.a] + rhs.val[p.b]);
		}
		return res;
	}
	int get() {
		return *min_element(val, val + 18);
	}
} t[400005];
void build(int p, int l, int r) {
	if (l == r) {
		for (int c = 0; c < 3; ++c) {
			int cur = ID(c == 0, c == 1, c == 2);
			t[p].val[cur] = (s[l] != c);	
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p] = t[p << 1] + t[p << 1 | 1];
}
void modify(int p, int l, int r, int pos) {
	if (l == r) {
		for (int c = 0; c < 3; ++c) {
			int cur = ID(c == 0, c == 1, c == 2);
			t[p].val[cur] = (s[pos	] != c);	
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= pos) {
		modify(p << 1, l, mid, pos);
	} else {
		modify(p << 1 | 1, mid + 1, r, pos);
	}
	t[p] = t[p << 1] + t[p << 1 | 1];
}
int main() {
	cin >> n >> q;
	cin >> (s + 1);
	for (int a1 = 0; a1 < 3; ++a1) {
		for (int b1 = 0; b1 < 3; ++b1) {
			for (int c1 = 0; c1 < 2; ++c1) {
				for (int a2 = 0; a2 < 3; ++a2) {
					for (int b2 = 0; b2 < 3; ++b2) {
						for (int c2 = 0; c2 < 2; ++c2) {
							int a3 = max(a1, a2);
							if (a1 == 1) {
								a3 = max(a3, 1 + b2);
							} else if (a1 == 2) {
								a3 = max(a3, 2 + c2);
							}
							if (a3 == 3) {
								continue;
							}
							int b3 = max(b1, b2);
							if (b1 && c2) {
								b3 = 2;
							}
							int c3 = max(c1, c2);
							tr.push_back({ID(a1, b1, c1), ID(a2, b2, c2), ID(a3, b3, c3)});
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		s[i] -= 'a';
	}
	build(1, 1, n);
	while (q--) {
		int i;
		char c;
		cin >> i >> c;
		s[i] = c - 'a';
		modify(1, 1, n, i);
		printf("%d\n", t[1].get());
	}
	return 0;
}