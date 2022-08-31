#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7;
int n, a[N], mx[N];
vi vc[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i], vc[a[i]].push_back(i);
	vi ns;
	int l = 1;
	while (l <= n) {
		int cur = 0, ml = l + 1;
		while (lower_bound(vc[cur].begin(), vc[cur].end(), l) != vc[cur].end()) 
			ml = max(ml, (*lower_bound(vc[cur].begin(), vc[cur].end(), l)) + 1), ++cur;
		l = ml;
		ns.push_back(cur);
	} 
	cout << sz(ns) << '\n';
	for (const int &u : ns) 
		cout << u << ' ';
	cout << '\n';
	L(i, 1, n) vc[a[i]].clear ();
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}