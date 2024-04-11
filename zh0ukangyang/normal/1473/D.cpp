#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, k;
int now[N], la[N], ra[N], lb[N], rb[N];
char s[N];
void Main() {
	cin >> n >> k >> (s + 1);
	L(i, 0, n + 1) now[i] = la[i] = ra[i] = lb[i] = rb[i] = 0;
	L(i, 1, n) {
		if(s[i] == '+') now[i] = now[i - 1] + 1;
		if(s[i] == '-') now[i] = now[i - 1] - 1;
		ra[i] = max(ra[i - 1], now[i]);
		la[i] = min(la[i - 1], now[i]);
	}
	R(i, n, 1) {
		if(s[i] == '+') lb[i] = lb[i + 1] + 1, rb[i] = rb[i + 1] + 1;
		if(s[i] == '-') lb[i] = lb[i + 1] - 1, rb[i] = rb[i + 1] - 1;
		lb[i] = min(lb[i], 0), rb[i] = max(rb[i], 0); 
	}
	while(k--) {
		int l, r; cin >> l >> r;
		int v = now[l - 1], fl = la[l - 1], fr = ra[l - 1];
		fl = min(fl, v + lb[r + 1]), fr = max(fr, v + rb[r + 1]);
		cout << fr - fl + 1 << endl; 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main(); 
	return 0;
}