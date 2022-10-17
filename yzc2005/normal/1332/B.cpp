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

const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int t, n, m, a[1005], c[1005];

int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i], c[i] = 0;
		m = 0;
		fu(j, 0, 10) {
			bool flg = 0;
			fu(i, 1, n) if((!c[i]) && (a[i] % p[j] == 0)) {
				if(!flg) flg = 1, ++m;
				c[i] = m;
			}
		}
		cout << m << endl;
		for(int i = 1; i <= n; ++i) {
			cout << c[i];
			if(i < n) cout << ' ';
			else cout << endl;
		}
	}
	return 0;
}