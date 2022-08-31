#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 107;
int n, a[N], b[N], sum;
bitset < N * N * 2 > bs;
void Main () {
	sum = 0;
	cin >> n;
	bs.reset();
	L(i, 1, n) {
		cin >> a[i];
		sum += a[i];
	}
	L(i, 1, n) {
		cin >> b[i];
		sum += b[i];
	}
	bs.set(0);
	L(i, 1, n) 
		bs = (bs << a[i]) | (bs << b[i]);
	int ns = 1e9;
	L(i, 0, sum) if(bs[i]) {
		ns = min(ns, i * i + (sum - i) * (sum - i));
	} 
	L(i, 1, n) 
		ns += a[i] * a[i] * (n - 2), ns += b[i] * b[i] * (n - 2);
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