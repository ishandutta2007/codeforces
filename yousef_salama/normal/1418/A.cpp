#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		long long x, y, k;
		scanf("%lld %lld %lld", &x, &y, &k);
		printf("%lld\n", (k * (y + 1) + x - 3) / (x - 1) + k);
	}
	return 0;
}