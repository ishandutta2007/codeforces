#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e3 + 7;
int n, a[N][N];
void Main() {
	cin >> n ;
	L(i, 1, n * 2) L(j, 1, n * 2) cin >> a[i][j]; 
	int ns = 1e9;
	L(i, 0, 1) 
		L(j, 0, 1) 
			ns = min(ns, a[i ? (n + 1) : n * 2][j ? 1 : n]);
	L(i, 0, 1) 
		L(j, 0, 1) 
			ns = min(ns, a[j ? 1 : n][i ? (n + 1) : n * 2]);
	ll ret = ns;
	L(i, n + 1, n * 2) L(j, n + 1, n * 2) ret += a[i][j];
	cout << ret << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}