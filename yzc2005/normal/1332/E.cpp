#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}
#define fail puts("NO"), exit(0)
typedef long long ll;
typedef pair<int, int> P;
 
const int mod = 998244353;
 
inline long long ksm(long long a, long long b) {
	long long res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod, b >>= 1;
	} 
	return res;
}
 
int main() {
	long long n, m, l, r;
	cin >> n >> m >> l >> r;
	if((n & 1) && (m & 1)) {
		cout << ksm(r - l + 1, n * m) << endl;
		return 0;
	}
	long long odd, even;
	even = (r >> 1) - (l - 1 >> 1);
	odd = r - l + 1 - even;
	long long ny = ksm(2, mod - 2);
	long long ans = ksm(odd + even, n * m) + ksm(-odd + even + mod, n * m);
	cout << ans * ny % mod << endl;
}