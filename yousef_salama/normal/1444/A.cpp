#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		long long p, q;
		scanf("%lld %lld", &p, &q);
		
		if(p % q != 0){
			printf("%lld\n", p);
			continue;
		}
		
		long long res = 1;
		
		long long tq = q;
		for(int d = 2; d * d <= tq; d++){
			if(tq % d != 0)continue;
			
			long long tp = p;
			while(tp % q == 0)tp /= d;
			
			res = max(res, tp);
			
			while(tq % d == 0)tq /= d;
		}
		
		if(tq > 1){
			long long tp = p;
			while(tp % q == 0)tp /= tq;
			
			res = max(res, tp);
		}
		
		printf("%lld\n", res);
	}
	return 0;
}