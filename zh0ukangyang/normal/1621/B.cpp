#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7;
int n, l[N], r[N], ml, mr;
ll tl, tr, ok, c[N];
void Main() {
	ml = 1e9 + 7, mr = -1e9 - 7;
	ok = 2e9 + 7;
	tl = tr = 2e9 + 7;
	cin >> n;
	L(i, 1, n) {
		cin >> l[i] >> r[i] >> c[i];
		if(l[i] < ml) ok = 2e9 + 7, ml = l[i], tl = 2e9 + 7;
		if(r[i] > mr) ok = 2e9 + 7, mr = r[i], tr = 2e9 + 7;
		if(ml == l[i] && mr == r[i]) 
			ok = min(ok, c[i]);
		if(ml == l[i]) 
			tl = min(tl, c[i]);
		if(mr == r[i]) 
			tr = min(tr, c[i]);
		cout << min(ok, tl + tr) << '\n';
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}