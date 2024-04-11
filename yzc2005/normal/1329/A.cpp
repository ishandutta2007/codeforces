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

int n, m, a[100005];
long long s;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) cin >> a[i], s += a[i];
	for(int i = 1; i <= m; ++i) if(a[i] + i - 1 > n) puts("-1"), exit(0);
	if(s < n) puts("-1"), exit(0);
	bool flg = 0;
	for(int i = 1; i <= m; ++i) {	
		if(s + i - 1 < n) flg = 1;
		if(flg) cout << n - s + 1 << " ";
		else cout << i << " ";
		s -= a[i];
	}
}