#include <cstdio>

int gcd(int a, int b) {
	if (b==0) return a;
	else return gcd(b, a%b);
}

int main() {
	int n, a, b, t;
	scanf("%d%d%d", &a, &b, &n);
	for (t=1; ; t=1-t) {
		if (!t) {
			int g=gcd(b, n);
			if (g>n) break;
			n-=g;
		}
		else {
			int g=gcd(a, n);
			if (g>n) break;
			n-=g;
		}
	}
	printf("%d\n", t);
	return 0;
}