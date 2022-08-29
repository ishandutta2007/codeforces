#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7;
int n, dl[N], dr[N], a[N], tag[N], ns, pre[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) dl[i] = dr[i] = 0;
	L(i, 1, n) {
		cin >> a[i];
		if(!dl[a[i]]) dl[a[i]] = i;
		dr[a[i]] = i;
	}
	L(i, 1, n) pre[i] = max(pre[i - 1], dr[a[i]]);
	for (int l = 1; l <= n; ) {
		ns += 1;
		if(pre[l] == l) {
			l += 1;
		} else l = pre[l];
	}
	cout << n - ns << '\n';
	return 0;
}