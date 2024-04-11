#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, f1; ll k; bool flag;
void Print(int x) {
	for(int i = n / 2 - 1; ~i; --i)
		printf("%d", (x >> i) & 1);
}
inline int Rev(int x) {
	int ret = 0;
	for(int i = 0; i < n / 2; ++i)
		ret |= ((x >> i) & 1) << (n / 2 - 1 - i);
	return ret;
}
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, k); f1 = (1 << (n / 2)) - 1;
		for(int i = 0; i < 1 << (n / 2 - 1); ++i) {
			int siz = ((1 << (n / 2 - 1)) - i) << (1 + (n & 1));
			siz -= !i + (n & 1);
			if(k > siz) k -= siz;
			else {
				flag = true;
				for(int j = 1; j < 1 << (n / 2); ++j) {
					if(Rev(j) >= i && Rev((j ^ f1)) >= i) --k;
					if(!k) {
						Print(i);
						if(n & 1) printf("0");
						Print(j);
						printf("\n");
						break;
					}
				}
				if((n & 1) && k) {
					for(int j = 0; j < 1 << (n / 2); ++j) {
						if(Rev(j) >= i && Rev((j ^ f1)) > i) --k;
						if(!k) {
							Print(i);
							printf("1");
							Print(j);
							printf("\n");
							break;
						}
					}
				}
			}
			if(flag) break;
		}
		if(!flag) printf("-1\n");
	} return 0;
}