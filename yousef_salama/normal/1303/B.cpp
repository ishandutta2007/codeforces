#include <bits/stdc++.h>
using namespace std;

int T, n, g, b;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &n, &g, &b);
		
		int m = (n + 1) / 2;
		printf("%lld\n", max(1LL * n, 1LL * (m - 1) / g * b + m));
	}
	return 0;
}