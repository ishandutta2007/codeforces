#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, m, p[N], mp[N], ns = 0;
void slv(int L, int R, int cs) {
	if(L == R) return ;
//	cout << L << ' ' << R << endl;
	int l = 1, r = n - 1, op = 0;
	while(true) {
		int u = -1;
		ns += 1;
		if(!op) {
			while(!(L <= mp[l] && mp[l] <= R)) 
				++l;
			u = mp[l];
		} else {
			while(!(L <= mp[r] && mp[r] <= R)) 
				--r;
			u = mp[r];
		}
//		cout << u << endl;
		if(cs == u) return ;
		if(cs == 1) {
			R = u - 1;
		} else {
			L = u + 1;
		}
		op ^= 1;
	}
}
void Main() {
	cin >> n;
	L(i, 1, n) cin >> p[i], mp[p[i]] = i;
	ns = 0;
	slv(1, mp[n], 1);
	slv(mp[n], n, n);
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main(); 
	return 0;
}