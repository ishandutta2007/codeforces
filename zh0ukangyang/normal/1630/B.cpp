#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7;
int n, k, mk, a[N], cnt[N], ns, px, py;
bool vis[N];
void Main () {
	ns = 1e9;
	cin >>  n >> k;
	mk = (n + k + 1) / 2;
	L(i, 1, n) cnt[i] = 0;
	L(i, 1, n) cin >> a[i], cnt[a[i]] += 1;
	L(i, 1, n) cnt[i] += cnt[i - 1]; 
	int cur = 1;
	L(x, 1, n) {
		while(cur <= n && cnt[cur] - cnt[x - 1] < mk) ++cur;
		if(cur <= n) {
			if(cur - x + 1 < ns) {
				px = x;
				py = cur;
				ns = cur - x + 1;
			}
		}
	}
	cout << px << ' ' << py << '\n';
	int ret = 0, tk = k, lst = 0;
	if(tk > 1) {
	L(i, 1, n) {
		ret += (px <= a[i] && a[i] <= py) ? 1 : -1;
		if(ret > 0) {
			cout << lst + 1 << ' ' << i << '\n';
			ret = 0;
			lst = i;
			tk -= 1;
			if(tk == 1) break ;
		}
	}
	}
	cout << lst + 1 << ' ' << n << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}