#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <deque>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n, a[MAX_N], ret[MAX_N];
int nQ;
int sqrtN;

struct Query {
	int l, r, id;
	void read(int id) {
		this->id = id;
		scanf("%d%d", &l, &r);
		--l, --r;
	}
	bool operator<(const Query&o) const {
		if (l / sqrtN != o.l / sqrtN)
			return l / sqrtN < o.l / sqrtN;
		return r < o.r;
	}
};

Query qs[MAX_N];

deque<int> by[MAX_N];
int cntw[MAX_N], cnt[MAX_N], tot;

int l, r, ans;

void dec2(int at) {
	if (--cntw[at] == 0) {
		if (++tot == 1)
			--ans;
	}
}

void add2(int at) {
	if (++cntw[at] == 1) {
		if (--tot == 0)
			++ans;
	}
}

void dec(int at) {
	if (--cnt[at] == 0) {
		--ans;
		if (--tot == 0)
			++ans;
	}
}

void add(int at) {
	if (++cnt[at] == 1) {
		++ans;
		if (++tot == 1)
			--ans;
	}
}

void decLeft() {
	int x = a[--l], at = l;
	deque<int>&v = by[x];
	v.push_front(at);
	add(x);
	if (v.size() >= 3 && v[1] - v[0] != v[2] - v[1])
		add2(x);
}

void incLeft() {
	int x = a[l++];
	deque<int>&v = by[x];

	dec(x);
	if (v.size() >= 3 && v[1] - v[0] != v[2] - v[1])
		dec2(x);
	v.pop_front();
}

void incRight() {
	int x = a[++r], at = r;
	deque<int>&v = by[x];
	add(x);
	v.push_back(at);
	int m = v.size();
	if (v.size() >= 3 && v[m - 1] - v[m - 2] != v[m - 2] - v[m - 3])
		add2(x);
}

void decRight() {
	int x = a[r--];
	deque<int>&v = by[x];
	int m = v.size();
	dec(x);
	if (v.size() >= 3 && v[m - 1] - v[m - 2] != v[m - 2] - v[m - 3])
		dec2(x);
	v.pop_back();
}

int main() {
	scanf("%d", &n);
	sqrtN = 1;
	while (sqrtN * sqrtN < n)
		++sqrtN;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	scanf("%d", &nQ);
	for (int i = 0; i < nQ; ++i) {
		qs[i].read(i);
	}
	sort(qs, qs + nQ);

	l = 0, r = -1;

	for (int i = 0; i < nQ; ++i) {
		Query&q = qs[i];
		while (r < q.r)
			incRight();
		while (l > q.l)
			decLeft();
		while (r > q.r)
			decRight();
		while (l < q.l)
			incLeft();
		ret[q.id] = ans;
//		if (l == 1 && r == 9) {
//			cout << ans << " " << tot << endl;
//		}
	}

	for (int i = 0; i < nQ; ++i) {
		printf("%d\n", ret[i] + 1);
	}
}