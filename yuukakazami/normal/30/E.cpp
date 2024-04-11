#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = int(1e5) + 10;

void ZAlgorithm(char str[], char pat[], int len[]) {
	int n = strlen(str), p = strlen(pat);
	static int self[MAX_N];

	int c = 0, mxr = -1;
	for (int i = 1; i < p; ++i) {
		int j = 0;
		if (i < mxr)
			j = min(self[i - c], mxr - i);
		while (i + j < p && pat[i + j] == pat[j])
			++j;
		self[i] = j;
		if (i + j > mxr)
			mxr = i + j, c = i;
	}

	c = 0, mxr = -1;
	for (int i = 0; i < n; ++i) {
		int j = 0;
		if (i < mxr)
			j = min(self[i - c], mxr - i);
		while (i + j < n && j < p && str[i + j] == pat[j])
			++j;
		len[i] = j;
		if (i + j > mxr)
			mxr = i + j, c = i;
	}
}

void Manacher(char str[], int len[]) {
	int n = strlen(str);
	int c, mxr = -1;
	for (int i = 0; i < n; ++i) {
		int j = 0;
		if (i < mxr)
			j = min(len[2 * c - i], mxr - i);
		while (i - j >= 0 && i + j < n && str[i + j] == str[i - j])
			++j;
		len[i] = j;
		if (i + j > mxr)
			mxr = i + j, c = i;
	}
}

char str[MAX_N], rev[MAX_N];
int match[MAX_N], mxPalin[MAX_N];

int ret[MAX_N], who[MAX_N];
vector<int> byHere[MAX_N];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	strcpy(rev, str);
	reverse(rev, rev + n);
	ZAlgorithm(str, rev, match);
	Manacher(str, mxPalin);

	//[i,i+ri) x-i [i+ri,..) ri
	set<int> st;
	int mx = -1;
	for (int i = 0; i < n; ++i) {
		st.insert(i);
		if (mx == -1) {
			who[i] = *st.begin();
			ret[i] = i - who[i];
		} else {
			int a = *st.begin();
			if (i - a > match[mx])
				who[i] = a, ret[i] = i - a;
			else
				who[i] = mx, ret[i] = match[mx];
		}
		byHere[i + match[i]].push_back(i);
		for (vector<int>::iterator e = byHere[i].begin(); e != byHere[i].end(); ++e) {
			st.erase(*e);
			if (mx == -1 || match[*e] > match[mx])
				mx = *e;
		}
	}

	int ans = 0;
	vector<int> ls, rs;

	for (int i = 0; i < n; ++i) {
		int l = i - mxPalin[i] + 1, r = i + mxPalin[i] - 1;
		int a = min(n - 1 - r, ret[l]);
		int tmp = r - l + 1 + a * 2;
		if (tmp > ans) {
			ans = tmp;
			//build!
			ls.clear(), rs.clear();
			if (a > 0) {
				ls.push_back(who[l]), rs.push_back(who[l] + a - 1);
			}
			ls.push_back(l), rs.push_back(r);
			if (a > 0) {
				ls.push_back(n - a), rs.push_back(n - 1);
			}
		}
	}

	cout << ls.size() << endl;
	for (int i = 0; i < ls.size(); ++i) {
		cout << ls[i] + 1 << " " << rs[i] - ls[i] + 1 << endl;
	}
	return 0;
}