#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n;

int eval(int cnt[26], int scnt[26]) {
	int ret = 0;
	for (int i = 0; i < 26; ++i) {
		ret += min(cnt[i], scnt[i]);
	}
	return ret;
}

int main() {
	cin >> n;
	vector<string> name(n), surname(n);
	for (int i = 0; i < n; ++i) {
		cin >> name[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> surname[i];
	}
	sort(name.begin(), name.end());
	sort(surname.begin(), surname.end());
	int cnt[26] = { }, scnt[26] = { };
	for (int i = 0; i < n; ++i) {
		cnt[name[i][0] - 'A']++;
		scnt[surname[i][0] - 'A']++;
	}
	vector<bool> used(n, false);
	for (int i = 0; i < n; ++i) {
		cout << name[i] << " ";
		int who = -1, mx = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j]) {
				int tmp = 0;
				if (name[i][0] == surname[j][0])
					++tmp;
				--cnt[name[i][0] - 'A'];
				--scnt[surname[j][0] - 'A'];
				tmp += eval(cnt, scnt);
				if (tmp > mx) {
					mx = tmp;
					who = j;
				}
				++cnt[name[i][0] - 'A'];
				++scnt[surname[j][0] - 'A'];
			}
		cout << surname[who];
		--cnt[name[i][0] - 'A'];
		--scnt[surname[who][0] - 'A'];
		used[who] = true;
		if (i + 1 < n)
			cout << ", ";
	}
	cout << endl;
	return 0;
}