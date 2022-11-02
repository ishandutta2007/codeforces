#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 4000 + 1;
int dp[MAX_N][MAX_N];
string A, B;
int ci, cd, cr, ce;
int na[MAX_N][26], nb[MAX_N][26];

void prepare(const string&a, int next[][26]) {
	int n = a.size();
	fill(next[n], next[n] + 26, n);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) {
			if (a[i] - 'a' == j)
				next[i][j] = i;
			else
				next[i][j] = next[i + 1][j];
		}
	}
}

int main() {
	cin >> ci >> cd >> cr >> ce;
	cin >> A >> B;
	int nA = A.size(), nB = B.size();
	prepare(A, na);
	prepare(B, nb);
	for (int i = nA; i >= 0; --i) {
		for (int j = nB; j >= 0; --j) {
			int&c = dp[i][j];
			if (i == nA && j == nB) {
				c = 0;
			} else if (i == nA) {
				c = dp[i][j + 1] + ci;
			} else if (j == nB) {
				c = dp[i + 1][j] + cd;
			} else {
				c = min(dp[i + 1][j] + cd, dp[i][j + 1] + ci);
				c = min(c, dp[i + 1][j + 1] + (A[i] == B[j] ? 0 : cr));
				if (i + 2 <= nA && j + 2 <= nB) {
					c = min(c, dp[i + 2][j + 2] + ((A[i] != B[j + 1]) + (A[i + 1] != B[j])) * cr + ce);
					int na = ::nb[j + 1][A[i] - 'a'], nb = ::na[i + 1][B[j] - 'a'];
					if (na < nB && nb < nA) {
						int by = (nb - i - 1) * cd + (na - j - 1) * ci + ce;
						c = min(c, dp[nb + 1][na + 1] + by);
					}
				}
			}
		}
	}
	cout << dp[0][0] << endl;
	return 0;
}