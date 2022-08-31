#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 107;
int n, a[N], dp[N][N];
void Main () {
	memset(dp, -0x3f, sizeof(dp));
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
	}
	int ns = 1;
	L(i, 1, n) 
		L(j, i + 1, n) {
			int ret = 2;
			L(k, j + 1, n) 
				if((a[j] - a[i]) * (k - j) == (a[k] - a[j]) * (j - i)) 
					ret += 1;
			ns = max(ns, ret);
		}
	cout << n - ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}