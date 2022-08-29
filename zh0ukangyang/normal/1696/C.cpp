#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, m, k, a[N], b[N]; 
ll sa[N], wa[N], tpa;
ll sb[N], wb[N], tpb;
void slv(int *a, ll *stk, ll *w, ll &tp, int n) {
	tp = 0;
	L(i, 1, n) {
		cin >> a[i];
		int ret = 1;
		while(a[i] % m == 0) 
			a[i] /= m, ret *= m;
		if(tp && stk[tp] == a[i]) w[tp] += ret;
		else ++tp, stk[tp] = a[i], w[tp] = ret;
	}	
}
void Main() {
	cin >> n >> m;
	slv(a, sa, wa, tpa, n);
	cin >> k;
	slv(b, sb, wb, tpb, k);
	if(tpa != tpb) 
		return cout << "No\n", void ();
	L(i, 1, tpa) 
		if(sa[i] != sb[i] || wa[i] != wb[i]) 
			return cout << "No\n", void ();
	cout << "Yes\n"; 
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main(); 
	return 0;
}