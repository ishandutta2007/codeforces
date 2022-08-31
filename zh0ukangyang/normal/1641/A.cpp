#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7;
int n, x, a[N], val[N];
map < int, vi > mp;
int rc[N];
void Main () {
	mp.clear();
	cin >> n >> x; 
	L(i, 1, n) {
		cin >> a[i];
		int cnt = 0, w = a[i];
		while(w % x == 0) 
			++cnt, w /= x; 
		mp[w].emplace_back(cnt);
	}
	int ns = 0;
	for(auto u : mp) {
		for(auto t : u.second) 
			rc[t] += 1;
		L(i, 0, 29) {
			int mn = min(rc[i], rc[i + 1]);
			rc[i] -= mn, rc[i + 1] -= mn;
		}
		L(i, 0, 30) ns += rc[i], rc[i] = 0;
	}
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main ();
	return 0;
}