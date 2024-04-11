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



int main() {
	int t, a, b, c, d, x, y, x1, y1, x2, y2;
	cin >> t;
	while(t--) {
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int xx = x + b - a, yy = y + d - c;
		bool ok = 1;
		if(x1 <= xx && xx <= x2 && y1 <= yy && yy <= y2) {
			if((a || b) && x1 == x2) ok = 0;
			if((c || d) && y1 == y2) ok = 0;
		} else ok = 0;
		puts(ok ? "Yes" : "No");
	}
	return 0;
}