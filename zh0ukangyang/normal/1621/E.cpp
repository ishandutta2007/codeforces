#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 3e5 + 7;
int n, m, mp[N], a[N], k[N];
vi vc[N];
struct fc {
	ll x, y;
	fc (ll X = 0, ll Y = 0) {
		x = X;
		y = Y;
	}
} w[N], b[N], nw[N];
bool operator < (fc a, fc b) {
	return (ll) a.x * b.y < (ll) a.y * b.x;
}
int cnt[3][N];
int get (int o, int l, int r) {
	return cnt[o + 1][r] == cnt[o + 1][l - 1];
}
int ord[N];
void Main() {
	cin >> n >> m;
	L(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	reverse(a + 1, a + m + 1);
	L(i, 1, m) w[i] = fc (a[i], 1);
	L(i, 1, m) {
		cin >> k[i];
		b[i].x = 0, b[i].y = k[i];
		int w;
		L(g, 1, k[i]) cin >> w, vc[i].push_back(w), b[i].x += w;
	}
	L(i, 1, m) ord[i] = i;
	sort(ord + 1, ord + m + 1, [&] (int x, int y) {
		return b[x] < b[y]; 
	});
	L(i, 1, m) nw[i] = b[ord[i]], mp[ord[i]] = i; //, cout << nw[i].x << ", " << nw[i].y << '\n';
	L(o, -1, 1) L(i, 1, m) 
		cnt[o + 1][i] = w[i] < nw[i + o], cnt[o + 1][i] += cnt[o + 1][i - 1];
//	L(i, 1, m) 
//		cout << nw[i].x << ' ' << nw[i].y << '\n';
//	cout << "A : \n";
//	L(i, 1, m) cout << w[i].x << ' ' << w[i].y << '\n';
	L(x, 1, m) for (const int &u : vc[x]) {
		int i = mp[x];
		auto z = b[x];
		z.x -= u, z.y -= 1;
		int lb = lower_bound (nw + 1, nw + m + 1, z) - nw;
		if(lb > i) {
			cout << (get(0, 1, i - 1) && get(0, lb, m) && get(1, i, lb - 2) && !(w[lb - 1] < z));
		} else {
			cout << (get(0, 1, lb - 1) && get(0, i + 1, m) && get(-1, lb + 1, i) && !(w[lb] < z));
		}
	}
	cout << "\n";
	L(i, 0, m + 1) vc[i].clear (), cnt[0][i] = cnt[1][i] = cnt[2][i] = 0;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}
/*
2
1 1
30
3
25 16 37
4 2
9 12 13 6
3
111 11 11
2
4 5
*/