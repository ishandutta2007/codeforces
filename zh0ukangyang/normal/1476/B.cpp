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
int n, k;
ll f[N];
void Main() {
	n = read(), k = read();	
	ll sum = 0, ans = 0;
	L(i, 1, n) {
		f[i] = read();
		if(i != 1 && f[i] > sum * k / 100) {
			ll v = (100 * f[i] + k - 1) / k - sum;
			sum += v, ans += v;
		} 
		sum += f[i]; 
	}
	printf("%lld\n", ans);
}
int main() {
	int T = read();
	while(T--) Main(); 
	return 0;
}