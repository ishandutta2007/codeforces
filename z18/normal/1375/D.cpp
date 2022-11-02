#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
using namespace std;

const int maxn = 1e3;
int T, n, a[maxn + 5], cur, vis[maxn + 5];

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d", &n);
		rep(i, 0, n - 1) scanf("%d", &a[i]);
		vector<int> vec;
		while (true) {
			++cur;
			rep(i, 0, n - 1) vis[a[i]] = cur;
			int mex = 0;
			rep(i, 0, n) if (vis[i] != cur) { mex = i; break; }
			if (mex == n) {
				int t = -1;
				rep(i, 0, n - 1) if (a[i] != i) { t = i, vec.push_back(i); break; }
				if (t == -1) break;
				a[t] = mex;
			} else {
				vec.push_back(mex);
				a[mex] = mex;
			}
		}
		printf("%d\n", (int)vec.size());
		rep(i, 0, vec.size() - 1) printf("%d%c", vec[i] + 1, " \n"[i == vec.size() - 1]);
		if (vec.empty()) puts("");
	}
	return 0;
}