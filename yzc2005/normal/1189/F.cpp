#include <bits/stdc++.h> 
using namespace std;
#define mem(a, x) memset(a, x, sizeof a)
#define fu(i, a, b) for(int i = a; i <= b; ++i)
#define fd(i, a, b) for(int i = a; i >= b; --i)

const int N = 1005, mod = 998244353;
int n, a[N], k, dp[N][N], ans;

inline void addmod(int &a, int b) {a = (a + b) % mod;}
inline void mulmod(int &a, int b) {a = 1ll * a * b % mod;}
inline int add(int a, int b) {return (a + b) % mod;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}

int main() {
	cin >> n >> k;
	fu(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int lst = 0;
	dp[0][0] = 1, a[0] = -1e9;
	fu(b, 1, (a[n] - a[1]) / (k - 1) + 1) {
		fu(len, 1, k) {
			int s = 0, l = 0;
			fu(i, 1, n) {
				while(l < i && a[i] - a[l] >= b) addmod(s, dp[len - 1][l++]);
				dp[len][i] = s;
			}
		}
		int sum = 0;
		fu(i, 1, n) addmod(sum, dp[k][i]);
		addmod(ans, mul((lst - sum + mod) % mod, b - 1));
		lst = sum;
	} 
	cout << ans;	
}