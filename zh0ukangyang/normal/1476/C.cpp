#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
const db eps = 1e-5;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f; 
}
int n, k, a[N], b[N], c[N], len[N];
ll p[N];
void Main() {
	ll ans = 0;
	n = read();
	L(i, 1, n) c[i] = read();
	L(i, 0, n - 1) a[i] = read();
	L(i, 0, n - 1) b[i] = read();
	L(i, 1, n) {
		if(a[i] > b[i]) swap(a[i], b[i]);
		len[i] = c[i] - b[i] + a[i] - 1;
	}
	p[n - 1] = c[n] + 1;
	R(i, n - 1, 1) {
		ans = max(ans, p[i] + b[i] - a[i]);
		p[i - 1] = c[i] + 1;
		if(a[i] != b[i]) p[i - 1] = max(p[i - 1], p[i] + len[i] + 2);
	}
	printf("%lld\n", ans);
}
int main() {
	int T = read();
	while(T--) Main(); 
	return 0;
}