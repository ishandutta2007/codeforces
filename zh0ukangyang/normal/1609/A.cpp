#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 5e5 + 7;
int n;
ll a[N], b[N];
void Main () {
	ll ns = 0;
	cin >> n ;
	L(i, 1, n) 
		cin >> a[i], ns += a[i];
	sort(a + 1, a + n + 1);
	L(i, 1, n) {
		L(j, 1, n) b[j] = a[j];
		L(j, 1, n) if(i != j) {
//			cout << j << "IS " << b[j] << '\n';
			while (b[j] % 2 == 0) b[j] /= 2, b[i] *= 2;
			ll sum = 0;
			L(k, 1, n) sum += b[k];
			ns = max(ns, sum);
		}
	}
	cout << ns << '\n';
}
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}