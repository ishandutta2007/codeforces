#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
using namespace std;
template <typename T>
inline void read(T &x) {
    x = 0;
    LL f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
    x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
int n, k, m, t;
int main() {
	read(n); read(k); read(m); read(t);
	_rep(i, 1, t) {
		int opt, pos;
		read(opt); read(pos);
		if(opt == 0) {
			if(pos < k) {
				n -= pos; k -= pos;
			} else {
				n = pos;
			}
		} else {
			n++; 
			k += (pos <= k? 1 : 0);
		}
		cout << n << " " << k << endl;
	}
	return 0;
}