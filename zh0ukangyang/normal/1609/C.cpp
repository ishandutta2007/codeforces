#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7;
int n, e, a[N];
bool Prime[N]; 
int nx[N], en[N];
void Main () {
	cin >> n >> e;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n + e) nx[i] = en[i] = 0;
	ll ns = 0;
	R(i, n, 1) {
		if(a[i] == 1) {
			nx[i] = nx[i + e] + 1;
			en[i] = en[i + e] + 1;
		}
		else if(Prime[a[i]]) {
			nx[i] = 0;
			en[i] = nx[i + e] + 1;
		} else {
			nx[i] = en[i] = 0;
		}
//		cout << i << ":" << nx[i] << ' ' << en[i] << '\n';
		if(en[i] > 1) ns += en[i] - max(nx[i], 1);
	}
	cout << ns << '\n';
}
void xxs (int n) {
	L(i, 2, n) Prime[i] = true;
	L(i, 2, n) 
		if(Prime[i]) 
			L(j, 2, n / i) 
				Prime[j * i] = false;  
}
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	xxs (N - 7);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}