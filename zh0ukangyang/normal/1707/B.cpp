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
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];	
	}
	int cnt = n;
	L(test, 1, n - 1) {
		int q = 0;
		if(cnt != n - test + 1 && cnt > 0) q = a[1];
		L(i, 1, cnt - 1) a[i] = a[i + 1] - a[i];
		a[cnt] = q;
		int xcnt = 0;
		L(i, 1, cnt) if(a[i]) swap(a[i], a[++xcnt]);
		cnt = xcnt;
		sort(a + 1, a + cnt + 1);
		
//		L(i, 1, cnt) cout << a[i] << ",";
//		cout << endl;
	} 
	cout << a[1] << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}