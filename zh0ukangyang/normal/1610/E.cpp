#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7;
int n, a[N], nt[N];
void Main() {
	cin >> n;
	nt[n + 1] = 0;
	L(i, 1, n) cin >> a[i]; 
	R(i, n, 1) nt[i] = a[i] == a[i + 1] ? nt[i + 1] + 1 : 1;
	int ns = 0; 
	R(i, n, 1) {
		int p = i + nt[i], all = nt[i];
//		cout << "p = " << p << '\n'; 
		while (p <= n) 
			p = lower_bound(a + 1, a + n + 1, a[p] * 2 - a[i]) - a, all += 1;
		ns = max(ns, all);
	}
	cout << n - ns << '\n';
}
int main() { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}