#include <bits/stdc++.h>
using namespace std;

int n;
long long p, q, b;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%lld %lld %lld", &p, &q, &b);
		q /= __gcd(p, q);
		
		while(true){
			long long g = __gcd(q, b);
			if(g == 1)break;
			
			while(q % g == 0)q /= g;
		}
		
		if(q == 1)printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}