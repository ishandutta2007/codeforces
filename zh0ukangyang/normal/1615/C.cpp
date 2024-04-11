#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, inf = 1e9;
int n;
char s[N], t[N];
int calc (int o) {
	int cnta = 0, cntb = 0;
	L(i, 1, n) {
		if(s[i] == '0' && t[i] == '1') cnta += 1;
		if(s[i] == '1' && t[i] == '0') cntb += 1; 
	}
	return cnta + o == cntb ? cnta + cntb : inf; 
}
void Main () {
	cin >> n;
	cin >> (s + 1) >> (t + 1);
	int ret = calc(0);
	L(i, 1, n) t[i] = '0' + '1' - t[i];
	ret = min(ret, calc(1));
	if(ret == inf) cout << -1 << '\n';
	else cout << ret << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}