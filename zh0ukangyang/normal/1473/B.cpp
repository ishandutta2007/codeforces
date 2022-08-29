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
string s, t, ansa, ansb;
void Main() {
	ansa.clear(), ansb.clear();
	cin >> s >> t, n = s.size(), m = t.size();
	int Len = n * m / __gcd(n, m);
	L(i, 1, Len / n) ansa = ansa + s;
	L(i, 1, Len / m) ansb = ansb + t;
	if(ansa == ansb) cout << ansa << endl;
	else cout << "-1\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main(); 
	return 0;
}