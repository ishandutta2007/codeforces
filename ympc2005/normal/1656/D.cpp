#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

ll n;

int T;

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%lld", &n);
		int cnt = 0;
		
		while (n%2 == 0) {
			n /= 2;
			cnt++;
		}
		
		if (n == 1) {
			puts("-1");
		} else {
			if ((1ll<<cnt + 1) + 1 <= n) {
				printf("%lld\n", 1ll<<cnt + 1);
			} else if (1ll*n*(n + 1)/2 <= (n<<cnt)){
				printf("%lld\n", n);
			} else {
				puts("-1");
			}
		}
	}
}