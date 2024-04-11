#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = int(1e5) + 10;

struct TA {
	int a[MAX_N], n;
	void init(int n) {
		this->n = n;
		memset(a, 0, sizeof a);
	}
	void add(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}
	int get(int p) {
		int r = 0;
		for (p++; p; p -= p & -p)
			r += a[p - 1];
		return r;
	}
} ta;
int a[MAX_N];

struct Node {
	int val, idx;
	Node(int val, int idx) :
			val(val), idx(idx) {
	}
};

void putOn(Node&a, Node b) {
	a.val += b.val;
	ta.add(a.idx, b.val);
}

int main() {
	int n, Q;
	cin >> n >> Q;
	ta.init(n);

	deque<Node> que;

	for (int i = 0; i < n; ++i) {
		a[i] = 1;
		ta.add(i, 1);
		que.push_back(Node(a[i], i));
	}
	bool rev = false;
	while (Q--) {

//		for (int i = 0; i < n; ++i) {
//			cout << que[i].val << " ";
//		}
//		cout << endl;

		int cmd;
		scanf("%d", &cmd);
		if (cmd == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			--r;
			int L, R;
			if (!rev) {
				L = que[l].idx;
				R = que[r].idx;
			} else {
				L = que[que.size() - 1 - l].idx;
				R = que[que.size() - 1 - r].idx;
			}
			if (L > R)
				swap(L, R);
			printf("%d\n", ta.get(R) - ta.get(L - 1));
		} else {
			int q;
			scanf("%d", &q);
			if (!rev) {
				if (q * 2 <= que.size()) {
					vector<Node> get;
					for (int i = 0; i < q; ++i) {
						get.push_back(que.front());
						que.pop_front();
					}
					for (int i = 0; i < q; ++i) {
//						ta.add(que[i].idx, get[q - 1 - i].val);
						putOn(que[i], get[q - 1 - i]);
					}
				} else {
					int last = que.size() - q;
					vector<Node> get;
					for (int i = 0; i < last; ++i) {
						get.push_back(que.back());
						que.pop_back();
					}
					for (int i = 0; i < last; ++i) {
						putOn(que[que.size() - 1 - i], get[last - 1 - i]);
					}
					rev ^= 1;
				}
			} else {
				if (q * 2 <= que.size()) {
					int last = q;
					vector<Node> get;
					for (int i = 0; i < last; ++i) {
						get.push_back(que.back());
						que.pop_back();
					}
					for (int i = 0; i < last; ++i) {
						putOn(que[que.size() - 1 - i], get[last - 1 - i]);
					}
				} else {
					int last = que.size() - q;
					vector<Node> get;
					for (int i = 0; i < last; ++i) {
						get.push_back(que.front());
						que.pop_front();
					}
					for (int i = 0; i < last; ++i) {
						putOn(que[i], get[last - 1 - i]);
					}
					rev ^= 1;
				}
			}
		}
	}
}