#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = a; i <= b; ++i)
#define fd(i, a, b) for(rg int i = a; i >= b; --i)
inline void read(int &x) {
	x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
}
 
const int N = 25;
int n, m, q, x;
string s1[N], s2[N];
 
int main() {
	cin >> n >> m;
	fu(i, 1, n) cin >> s1[i];
	fu(i, 1, m) cin >> s2[i];
	cin >> q;
	fu(i, 1, q) {
		cin >> x;
		int p1 = x % n, p2 = x % m;
		if(!p1) p1 = n;
		if(!p2) p2 = m;
		cout << s1[p1] << s2[p2] << endl;
	} 
}