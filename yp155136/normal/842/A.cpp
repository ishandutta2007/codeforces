#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

int main () {
	LL l,r,x,y,k;
	cin >>l >> r >> x >> y >> k;
	for (LL i=x;y>=i;i++) {
		if (l<= i*k && i*k <= r) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}