#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
typedef long long int64;

int n, m, k;

struct Subject {
	int64 l, r;
	int c, idx;
	int64 am[200][200];
	Subject*prevSubject[200][200];
	int prevIdx[200][200];

	void read() {
		cin >> l >> r >> c;
		memset(am, 0, sizeof am);
		for (int i = 0; i <= r - l; ++i) {
			am[1][i] = l + i;
		}
	}

	bool operator<(const Subject&s) const {
		return c < s.c;
	}

	void update(Subject&p) {
		if (p.c < c) {
			for (int prevDay = 1; prevDay < n; ++prevDay) {
				for (int64 prevValue = p.l; prevValue <= p.r; ++prevValue) {
					int64 c = p.am[prevDay][prevValue - p.l];
					if (c == 0)
						continue;
					for (int ch = 0; ch < 2; ++ch) {
						int64 curValue = ch ? prevValue + k : prevValue * k;
						if (curValue >= l && curValue <= r) {
							int idx = curValue - l;
							int64 nc = c + curValue;
							int curDay = prevDay + 1;
							if (nc > am[curDay][idx]) {
								am[curDay][idx] = nc;
								prevSubject[curDay][idx] = &p;
								prevIdx[curDay][idx] = prevValue - p.l;
							}
						}
					}
				}
			}
		}
	}
};

int main() {
	cin >> n >> m >> k;
	vector<Subject> subjects(m);
	for (int i = 0; i < m; ++i) {
		subjects[i].read();
		subjects[i].idx = i + 1;
	}
	sort(subjects.begin(), subjects.end());
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < i; ++j) {
			subjects[i].update(subjects[j]);
		}
	}
	Subject*end = 0;
	int endIdx;
	for (int i = 0; i < m; ++i) {
		Subject&cur = subjects[i];
		int maxIdx = max_element(cur.am[n], cur.am[n] + cur.r - cur.l + 1) - cur.am[n];
		if (end == 0 || cur.am[n][maxIdx] > end->am[n][endIdx]) {
			end = &cur;
			endIdx = maxIdx;
		}
	}
	if (end->am[n][endIdx] == 0) {
		cout << "NO" << endl;
		return 0;
	}
	vector<int64> pa, pb;
	for (int i = n; i >= 1; --i) {
		pa.push_back(end->idx);
		pb.push_back(end->l + endIdx);
		Subject*tmp = end;
		int tIdx = endIdx;
		end = tmp->prevSubject[i][tIdx];
		endIdx = tmp->prevIdx[i][tIdx];
	}
	cout << "YES" << endl;
	for (int i = n - 1; i >= 0; --i) {
		cout << pa[i] << " " << pb[i] << endl;
	}
	return 0;
}