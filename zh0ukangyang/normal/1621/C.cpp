#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7;
int n, q[N], cq[N], ns[N], p[N] = {0, 4, 2, 1, 3};
int ask (int x) {
	cout << "? " << x << endl;
	ll w = q[x];
	cin >> w;
//	L(i, 1, n) cq[i] = q[p[i]];
//	L(i, 1, n) q[i] = cq[i];
	return w;
}
int arr[N], tp;
void Main() {
	cin >> n;
	L(i, 1, n) q[i] = i, ns[i] = 0;
	L(i, 1, n) if(!ns[i]) {
		while (ask (i) != i) ; 
		tp = 0;
		while (arr[tp] != i) arr[++tp] = ask(i);
		L(j, 1, tp) ns[arr[j]] = arr[j % tp + 1];
	}
	cout << "! ";
	L(i, 1, n) {
		cout << ns[i] << ' ';
	}
	cout << endl;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}