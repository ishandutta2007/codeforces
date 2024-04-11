#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//prefix used length

typedef long long int64;
const int64 INF = 1LL << 60;

struct Data {
	//[L..R] R-x -> L+x
	int64 dist[10][10];
	Data() {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				dist[i][j] = INF;
			}
		}
	}
};

Data dp[512][20]; //prefix..used length
bool memo[512][20];

Data&calc(int used, int length) {
	//prefix[used] length*0
	if (memo[used][length])
		return dp[used][length];
	memo[used][length] = true;

	Data&ret = dp[used][length];

	if (length == 1) {
		//used9 -> used 0
		int64 dp2[10][10];
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				dp2[i][j] = INF;
			}
		}

		for (int i = 9; i >= 0; --i) {
			int64*dp = dp2[i];
			dp[i] = 0;
			for (int k = i; k > 0; --k) {
				for (int a = 1; a <= 9; ++a) {
					if ((used >> (a - 1) & 1) || (a == k)) {
						dp[k - a] = min(dp[k - a], dp[k] + 1);
					}
				}
			}
		}

		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				int a = 9 - i, b = j;
				//a->b
				if (a < b)
					ret.dist[i][j] = INF;
				else
					ret.dist[i][j] = dp2[a][b];
			}
		}
		return ret;
	}

	Data cur = calc(used | (1 << 8), length - 1);

	for (int digit = 9 - 1; digit >= 0; --digit) {
		int nused = used;
		if (digit > 0)
			nused |= 1 << (digit - 1);
		Data mid = calc(nused, length - 1);
		//merge!
		Data ncur;
		for (int lst = 0; lst < 10; ++lst) {
			int prevd = digit + 1;
			//used,prevd,length-1
			//L+lst
			for (int a = 1; a < 10; ++a) {
				if (a == prevd || (used >> (a - 1) & 1)) {
					//L+lst-a
					if (lst - a < 0) {
						int b = -(lst - a) - 1;
						for (int p = 0; p < 10; ++p) {
							for (int q = 0; q < 10; ++q) {
								ncur.dist[p][q] = min(ncur.dist[p][q],
										cur.dist[p][lst] + 1 + mid.dist[b][q]);
							}
						}
					}
				}
			}
		}
		cur = ncur;
	}

	return ret = cur;
}

struct Result {
	int64 L, R;
	int64 dist[10][10];			//R-x -> L-y

	Result() {
		L = R = -1;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				dist[i][j] = INF;
			}
		}
	}

	void write() {
		cout << R << " " << L << endl;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (dist[i][j] != INF) {
					cout << R - i << "->" << L - j << " " << dist[i][j] << endl;
				}
			}
		}
	}
};

bool canJump(int64 x, int64 y) {
	int64 i = x;
	while (i > 0) {
		int d = i % 10;
		if (x - d == y)
			return true;
		i /= 10;
	}
	return false;
}

int a[20], L;

int getUsed(int64 prefix) {
	int used = 0;
	while (prefix > 0) {
		int d = prefix % 10;
		if (d > 0)
			used |= 1 << (d - 1);
		prefix /= 10;
	}
	return used;
}

int calc(int n) {
	static int dp[int(1e6) + 10];
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int x = i;
		dp[i] = 1 << 30;
		while (x > 0) {
			int d = x % 10;
			dp[i] = min(dp[i], dp[i - d] + 1);
			x /= 10;
		}
	}
	return dp[n];
}

int main() {
	int64 n;
	cin >> n;
//	cout << calc(n) << endl;

	++n;

	Result ans;
	while (n > 0) {
		int64 prefix = n, pw = 1;
		int len = 0;
		while (prefix % 10 == 0)
			prefix /= 10, pw *= 10, ++len;

		//prefix+pw-1 -> prefix
		Result cur;
		cur.R = prefix * pw - 1, cur.L = (prefix - 1) * pw;
		n = cur.L;
		--prefix;

		if (len > 0) {
			int used = getUsed(prefix);
			Data ret = calc(used, len);
//			cout << cur.R << " " << cur.L << endl;
//
//			for (int i = 0; i < 10; ++i) {
//				for (int j = 0; j < 10; ++j) {
//					if (ret.dist[i][j] != INF) {
//						cout << cur.R - i << "->" << cur.L + j << " "
//								<< ret.dist[i][j] << endl;
//					}
//				}
//			}

			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					//R-i -> L+j
					//L+j
					for (int a = 0; a < 10; ++a) {
						if ((a > 0 && (used >> (a - 1) & 1)) || (a == j)) {
							//L+j-a
							if (j - a <= 0)
								cur.dist[i][a - j] = min(cur.dist[i][a - j],
										ret.dist[i][j] + 1);
						}
					}
				}
			}
		} else {
			cur.dist[0][0] = 0;
			int used = getUsed(prefix);
			for (int i = 1; i < 10; ++i) {
				if (used >> (i - 1) & 1) {
					cur.dist[0][i] = 1;
				}
			}
		}

//		cur.write();

		if (ans.R == -1) {
			ans = cur;
		} else {
			//let's update!
			Result t;
			t.R = ans.R, t.L = cur.L;
			for (int i = 0; i < 10; ++i) {
				for (int j = 1; j < 10; ++j) {
					if (ans.dist[i][j] != INF) {
						//ans.R-i - ans.L-j
						int k = j - 1;
						for (int l = 0; l < 10; ++l) {
							t.dist[i][l] = min(t.dist[i][l],
									ans.dist[i][j] + cur.dist[k][l]);
						}
						if (len == 0) {
							t.dist[i][j - 1] = min(t.dist[i][j - 1],
									ans.dist[i][j]);
						}
					}
				}
			}
			ans = t;
		}

//		ans.write();
	}

	cout << ans.dist[0][0] << endl;
	return 0;
}