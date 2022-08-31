#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
const ll inf = 1e18;
int n, m, tp;
ll ns, a[N], arr[N];
void calc() {
	sort(a + 1, a + n + 1);
	if(a[1] == 0 && a[n] == 0) return ns = 0, void ();
	if(a[1] > 0 || a[n] < 0) return ns = inf, void ();
	ll all = 0, buf = 0;
	tp = 0;
	L(i, 2, n) {
		if(a[i] > 0) all += a[i] * a[1], buf += a[i] + a[1];
		else arr[++tp] = -a[i], all += a[i] * a[n], buf += a[i] + a[n];
	}
//	cout << "tp = " << tp << '\n';
	sort(arr + 1, arr + tp + 1);
	L(i, 1, tp) {
		ns = max(ns, arr[i - 1] * buf + all);
		ns = max(ns, arr[i] * buf + all);
		all += -arr[i] * (a[1] - a[n]);
		buf += a[1] - a[n];
	}
	if(buf > 0) return ns = inf, void ();
	ns = max(ns, arr[tp] * buf + all);
}

void Main () {
	cin >> n;
	ns = -inf;
	L(i, 1, n) cin >> a[i];
	calc();
	L(i, 1, n) a[i] = -a[i]; 
	calc();
	if(ns >= inf) 
		cout << "INF" << '\n';
	else 
		cout << ns << '\n';
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}