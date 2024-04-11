#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7;
int n, k;
void Main() {
	cin >> n >> k;
	if(k * 2 - 1 > n) {
		cout << "-1\n";
		return ;
	}
	L(i, 1, n) {
		L(j, 1, n) {
			if(i == j && i % 2 == 1 && i <= 2 * k) {
				cout << "R";
			}
			else cout << ".";
		}
		cout << '\n';
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}