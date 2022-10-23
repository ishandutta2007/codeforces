#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7;
int n, a[N], pre[N]; 
int dp[3];
bool vis[N];
void Main() {
	cin >> n;
	int s = 0;
	L(i, 1, n) cin >> a[i], vis[i] = false, s += a[i];
	if(s % 2) {
		cout << "-1\n";
		return ;
	}
	int dec = s / 2;
	if(dec > 0) {
		L(i, 2, n) if(a[i] == 1 && !vis[i - 1] && dec > 0) vis[i] = true, --dec; 
	} else {
		L(i, 2, n) if(a[i] == -1 && !vis[i - 1] && dec < 0) vis[i] = true, ++dec;
	}
	if(dec) {
		cout << -1 << '\n';
		return ;
	}
	vector < pair < int, int > > vc;
	L(i, 1, n) {
		int j = i;
		while(j < n && vis[j + 1] != vis[j]) ++j;
		vc.push_back({i, j});
		i = j;
	} 
	cout << sz(vc) << '\n';
	for(auto u : vc) 
		cout << u.first  << ' ' << u.second << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}