#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		long long a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		
		long long n = c / d;
		long long r = c % d;
		
		if(a - n * b * d - b * r > 0){
			printf("-1\n");
			continue;
		}
		
		long long m = a / (b * d);
		printf("%lld\n", (m + 1) * a - m * (m + 1) / 2 * b * d);
	}
	return 0;
}