#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

string S[120];
int n;

bool g[26][26];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
	}

	for (int i = 0; i + 1 < n; ++i) {
		string a = S[i], b = S[i + 1];
		int L = 0;
		for (int i = 0; i < a.size() && i < b.size(); ++i) {
			if (a[i] == b[i])
				++L;
			else
				break;
		}
		if (L == b.size()) {
			puts("Impossible");
			return 0;
		}
		if (L == a.size())
			continue;
		g[a[L] - 'a'][b[L] - 'a'] = true;
	}

	for (int k = 0; k < 26; ++k) {
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				g[i][j] |= g[i][k] & g[k][j];
			}
		}
	}

	for (int i = 0; i < 26; ++i) {
		if (g[i][i]) {
			puts("Impossible");
			return 0;
		}
	}

	bool used[26] = { };
	for (int k = 0; k < 26; ++k) {
		for (int i = 0; i < 26; ++i)
			if (!used[i]) {
				bool ok = true;
				for (int j = 0; j < 26; ++j)
					if (!used[j] && g[j][i]) {
						ok = false;
					}
				if (ok) {
					used[i] = true;
					putchar('a' + i);
					break;
				}
			}
	}
	puts("");
	return 0;
}