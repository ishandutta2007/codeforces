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
int n, stk[N], tp;
char s[N]; 
bool vis[N];
void Main() {
	cin >> n >> (s + 1);
	n *= 2;
	int ns = 0;
	L(i, 0, n) vis[i] = false;
	L(i, 1, n) {
		if(s[i] == '(') {
			++tp;
		} else {
			vis[tp] = false, --tp, ns += !vis[tp], vis[tp] = true;
		}
	}
	cout << ns << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}