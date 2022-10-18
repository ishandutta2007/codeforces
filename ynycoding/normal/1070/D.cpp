#include<cstdio>
const int maxn = 200050;
int n, k;
int a[maxn];
inline int read() {
	int a = 0, c = getchar(), w = 1;
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') w = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) a = a * 10 + c - '0';
	return a * w;
}

int main() {
	n = read(); k = read();
	for(int i = 0; i < n; i++) a[i] = read();
	long long ans = 0; int rem1 = 0, rem2 = 0;
	for(int i = 0; i < n; i++) {
		rem1 = a[i];
		if(rem1+rem2 >= k) {
			ans += (rem1+rem2) / k;
			rem1 -= (rem1+rem2)/k*k - rem2;
			rem2 = 0;
		}else if(rem2) {
			rem1 = rem2 = 0;
			ans++;
		}
		rem2 = rem1;
	}
	if(rem2) ans++;
	printf("%I64d\n", ans);
	return 0;
}