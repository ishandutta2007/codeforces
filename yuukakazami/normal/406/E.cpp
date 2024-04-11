#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX_N = int(1e5) + 10;
int N, n;
vector<int> a[2];
int ans = 0;

typedef long long int64;

int mx;
int64 cnt;

void updateAnswer(int nmx, int64 ncnt) {
	if (nmx > mx) {
		mx = nmx;
		cnt = ncnt;
	} else if (nmx == mx) {
		cnt += ncnt;
	}
}

void rev(vector<int>&a) {
	for (int i = 0; i < a.size(); ++i) {
		a[i] = N - a[i];
	}
	reverse(a.begin(), a.end());
}

void solve(vector<int> a0, vector<int> a1) {
	//1 a0 2 a1
	//fix c in a0
	//a,b in a1
	//maximize 2n+|a-b|-|a-c|-|b-c|
	//a<b<=c : 2b-2c
	vector<pair<int, int> > v;
	for (int i = 0; i < a0.size(); ++i) {
		v.push_back(make_pair(a0[i], 0));
	}
	for (int i = 0; i < a1.size(); ++i) {
		v.push_back(make_pair(a1[i], 1));
	}
	sort(v.begin(), v.end());
	int L = 0;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i].second == 0) {
			int R = a1.size() - L;
			if (L > 0 && R > 0)
				updateAnswer(2 * N, 1LL * L * R);
		} else {
			++L;
		}
	}

	int A = 0;
	int B = -1, cntB = 0;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i].second == 0) {
			int C = v[i].first;
			if (cntB + A >= 2) {
				int what = 2 * N + B * 2 - C * 2;
				int64 total = 1LL * cntB * (cntB - 1) / 2 + 1LL * cntB * A;
				updateAnswer(what, total);
			}
		} else {
			int me = v[i].first;
			if (me > B) {
				A += cntB;
				B = me, cntB = 1;
			} else {
				cntB++;
			}
		}
	}

	for (int i = 0; i < v.size(); ++i) {
		v[i].first = N - v[i].first;
	}
	reverse(v.begin(), v.end());
	A = 0;
	B = -1, cntB = 0;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i].second == 0) {
			int C = v[i].first;
			if (cntB + A >= 2) {
				int what = 2 * N + B * 2 - C * 2;
				int64 total = 1LL * cntB * (cntB - 1) / 2 + 1LL * cntB * A;
				updateAnswer(what, total);
			}
		} else {
			int me = v[i].first;
			if (me > B) {
				A += cntB;
				B = me, cntB = 1;
			} else {
				cntB++;
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int s, f;
		cin >> s >> f;
		a[s].push_back(f);
	}
	mx = -1;
	for (int i = 0; i < 2; ++i) {
		sort(a[i].begin(), a[i].end());
		if (a[i].size() >= 3) {
			vector<int>&v = a[i];
			int L = count(v.begin(), v.end(), v[0]);
			int R = count(v.begin(), v.end(), v.back());
			int M = v.size() - L - R;
			if (v[0] == v.back()) {
				int tot = v.size();
				updateAnswer(0, 1LL * tot * (tot - 1) * (tot - 2) / 6);
				continue;
			}
			int64 cnt = 1LL * L * M * R;
			cnt += 1LL * L * (L - 1) / 2 * R;
			cnt += 1LL * L * R * (R - 1) / 2;
			updateAnswer(v.back() - v[0], cnt);
		}
	}
	solve(a[0], a[1]);
	solve(a[1], a[0]);
	cout << cnt << endl;
}