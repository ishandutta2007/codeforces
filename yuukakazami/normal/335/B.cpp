#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = 50000 + 10, MAX_LEN = 100 + 3, INF = ~0U >> 2;
int dp[MAX_N][MAX_LEN]; //i,j,min_right
int pr[MAX_N][MAX_LEN];
int nxt[MAX_N][26];
int n;
string s;

int main() {
	cin >> s;
	n = s.size();
	fill(nxt[n], nxt[n] + 26, INF);

	for (int i = n - 1; i >= 0; --i) {
		memcpy(nxt[i], nxt[i + 1], sizeof nxt[i]);
		nxt[i][s[i] - 'a'] = i;
	}

	for (int i = 0; i < n; ++i) {
		dp[i][0] = i; //[i,i)
		dp[i][1] = i + 1; //[i,i+1)
		dp[i][2] = nxt[i + 1][s[i] - 'a'] + 1;
	}

	for (int j = 3; j <= 100; ++j) {
		int minRight = INF, by = -1;
		for (int i = n - 1; i >= 0; --i) {
			//dp[i][j]
			if (minRight < INF) {
				dp[i][j] = nxt[minRight][s[i] - 'a'] + 1;
				pr[i][j] = by;
			} else
				dp[i][j] = INF;
			if (dp[i][j - 2] < minRight) {
				minRight = dp[i][j - 2];
				by = i;
			}
		}
	}

	int bj, bi;
	for (int j = 100; j >= 1; --j) {
		for (int i = 0; i < n; ++i)
			if (dp[i][j] < INF) {
				bj = j, bi = i;
				goto out;
			}
	}
	out: {
	}

	//write out
	string t = "";
	while (bj >= 2) {
		t += s[bi];
		bi = pr[bi][bj];
		bj -= 2;
	}
	string rev = t;
	reverse(rev.begin(), rev.end());
	string ans = t;
	if (bj == 1)
		ans += s[bi];
	ans += rev;
	cout << ans << endl;
}