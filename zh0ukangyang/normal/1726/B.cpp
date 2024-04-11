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
int n, m;
void Main() {
	cin >> n >> m;
	if(m < n) {
		cout << "No\n";
	} else if(n % 2 == 1) {
		cout << "Yes\n";
		L(i, 1, n - 1) {
			cout << 1 << ' ';
		}
		cout << m - n + 1 << '\n';
	} else if(m % 2) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		L(i, 1, n - 2) 
			cout << 1 << ' ';
		cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';
	}	
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}