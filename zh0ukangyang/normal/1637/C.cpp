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
int n, a[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	bool ok = false;
	L(i, 2, n - 1) if(a[i] % 2 == 0) ok = true;
	ll sum = 0;
	L(i, 2, n - 1) 
		sum += (a[i] + 1) / 2;
	if(ok) {
		cout << sum << '\n';
	} else {
		bool qwq = false;
		L(i, 2, n - 1) if(a[i] != 1) qwq = true;
		if(!qwq || n == 3) {
			cout << -1 << '\n';
		} else {
			cout << sum << '\n';
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) Main ();
	
	return 0;
}