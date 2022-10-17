#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
using namespace std;
int read() {
	int x = 0; char c = ' ';
	for(; !isdigit(c); c = getchar()) ;
	for(; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
	return x;
}
const int MAXN = (1 << 16 | 1);
int AND(int x, int y) {
	cout << "AND " << x << ' ' << y << endl;
	int X; cin >> X; return X;
}
int OR(int x, int y) {
	cout << "OR " << x << ' ' << y << endl;
	int X; cin >> X; return X;
}
int XOR(int x, int y) {
	assert(x != y);
	cout << "XOR " << x << ' ' << y << endl;
	int X; cin >> X; return X;
}
int s[MAXN], lst[MAXN], a[MAXN];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, vsm = -1, sm, vns = -1, ns = -1; lst[0] = 1; cin >> n;
	For(i, 2, n) {
		s[i] = XOR(1, i);
		if(lst[s[i]] && vsm == -1) vsm = OR(i, lst[s[i]]), sm = i; lst[s[i]] = i;
		if(s[i] == n - 1) ns = i;
	}
	if(vsm != -1) {
		a[1] = vsm ^ s[sm];
	} else {
		assert(ns != -1);
		int Y = ns == 2 ? 3 : 2;
		int x = AND(1, Y) * 2 + (s[Y]), y = n - 1, z = AND(Y, ns) * 2 + (s[ns] ^ s[Y]);
		
		a[1] = (x + y + z) / 2 - z;
	}
	For(i, 2, n) a[i] = a[1] ^ s[i];
	cout << "! "; For(i, 1, n) cout << a[i] << ' '; cout << endl;
	return 0;
}
/*
1 3 4
*/