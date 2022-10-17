#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
		#define eprintf(...) fprintf(stderr, _VA_ARGS_)
#else
		#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , int> pli;
typedef pair<ll , ll> pll;
typedef long double ld;
typedef vector< int > vi;
typedef unsigned long long ull;
#define mp make_pair
#define fi first
#define se second
const ll T = 1e7 + 1;

template <typename T> inline void chkmax(T &x,T y) { x = max(x,y); }
template <typename T> inline void chkmin(T &x,T y) { x = min(x,y); }
template <typename T> inline void read(T &x) {
    T f = 1; x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}
int main() {
		
		ll R;
		read(R);
		for (ll X = 1; X <= T; ++X) {
				ll Y = (R - X * X - X - 1) / (2 * X);
				if (Y > 0 && 1LL * X * X + 2LL * X * Y + X + 1 == R) {
						cout<< X << ' ' << Y << '\n';
						return 0;
				}
		} 
		cout<< "NO" << "\n";
				
		return 0;
	
}