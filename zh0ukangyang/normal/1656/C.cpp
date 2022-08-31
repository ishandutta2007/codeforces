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
int n, m, a[N];
void Main() {
	cin >> n ;
	L(i, 1, n) {
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	bool op1 = false, op2 = false;
	L(i, 1, n) 
		if(a[i] == 1) 
			op1 = true;
	L(i, 1, n - 1) 
		if(a[i] + 1 == a[i + 1]) 
			op2 = true;
	if(op1 && op2) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}