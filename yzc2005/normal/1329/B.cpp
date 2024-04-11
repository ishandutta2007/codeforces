// 
//--Violet Evergarden
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

int t, n, m, a[40];
long long s;

int main() {
	ios::sync_with_stdio(false);
	cin >> t; while(t--) {
		cin >> n >> m;
		int cnt = 0;
		for(int i = 0; ; ++i) {
			if(n <= (1 << (i + 1)) - 1) {
				a[++cnt] = (n ^ (1 << i)) + 1;
				break;
			} 
			a[++cnt] = (1 << i);
		}
		int ans = 1;
		fu(i, 1, cnt) ans = 1ll * ans * (a[i] + 1) % m;
		cout << (ans - 1 + m) % m << endl;
	} 
}