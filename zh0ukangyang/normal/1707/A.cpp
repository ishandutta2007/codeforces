#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 5e5 + 7;
int n, q, a[N];
bool vis[N];
void Main() {
	cin >> n >> q;
	L(i, 1, n) {
		cin >> a[i];	
	}
	int cur = 0;
	R(i, n, 1) {
		if(a[i] <= cur) {
			vis[i] = true;
		} else if(cur < q) {
			cur += 1;
			vis[i] = true;
		} else vis[i] = false; 
	}
	L(i, 1, n) cout << vis[i];
	cout << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}