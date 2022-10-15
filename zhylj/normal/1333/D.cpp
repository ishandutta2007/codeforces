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

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

const int kN = 1e4 + 5;
const ll kMod = 998244353;

ll a[kN], t = 0; char str[kN]; int n, m, k, q;
std::vector <int> sp[kN];
int main() { int T = 1; //rd(T);
	while(T--) {
		rd(n, k); scanf("%s", str + 1);
		int s = 0;
		for(int i = 1; i <= n; ++i) a[i] = (str[i] == 'R');
		int usd = 1;
		while(true) {
			bool flag = true;
			for(int j = 2; j <= n; ++j)
				if(a[j] < a[j - 1]) {
					sp[usd].push_back(j - 1);
					flag = false;
					++s;
				}
			for(auto x : sp[usd])
				std::swap(a[x], a[x + 1]);
			if(flag) { --usd; break; }
			++usd;
		}
		if(usd > k || s < k) { printf("-1\n"); return 0; }
		for(int i = 1; i <= usd; ++i) {
			if(s - sp[i].size() > k - 1) {
				printf("%d ", sp[i].size());
				for(auto x : sp[i]) printf("%d ", x);
				printf("\n");
			} else if(s > k - 1) {
				printf("%d ", s - (k - 1));
				for(int j = 0; j < s - (k - 1); ++j) printf("%d ", sp[i][j]);
				printf("\n");
				for(int j = s - (k - 1); j < sp[i].size(); ++j) printf("1 %d\n", sp[i][j]);
			} else {
				for(auto x : sp[i]) printf("1 %d\n", x);
			}
			--k; s -= sp[i].size();
		}
	} return 0;
}