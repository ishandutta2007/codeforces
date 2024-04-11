#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n;
int calc (int x, int p) {
	int ns = (x >> (p + 1)) << p;
	if(x >> p & 1) 
		ns += x & ((1 << p) - 1), ns += 1;
	return ns;
}
void Main () {
	int l, r;
	cin >> l >> r; 
	int ns = 0;
	L(p, 0, 30) {
		ns = max(ns, calc (r, p) - calc(l - 1, p));
	}
	cout << r - l + 1 - ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}