#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, m, f[N];
void Main() {
	int maxn = 0;
	cin >> n >> m;
	L(i, 1, n) cin >> f[i], maxn = max(maxn, f[i]);
	sort(f + 1, f + n + 1);
	if(f[1] + f[2] <= m || maxn <= m) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main(); 
	return 0;
}