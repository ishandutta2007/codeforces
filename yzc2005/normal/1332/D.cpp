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

int k;

int main() {
	cin >> k;
	cout << "2 3" << endl;
	cout << (1 << 18) - 1 << ' ' << (1 << 17) << ' ' << 0 << endl;
	cout << k << ' ' << (k | (1 << 17)) << ' ' << k << endl;
	return 0;
}