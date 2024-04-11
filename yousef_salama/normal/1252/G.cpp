#include <bits/stdc++.h>
using namespace std;

long long n;
int main(){
	scanf("%lld", &n);
	
	if(n == 1){
		printf("1\n");
		return 0;
	}
	
	int cnt = 0;
	long long f = -1;
	
	for(long long d = 2; d * d <= n; d++){
		if(n % d == 0){
			cnt++;
			f = d;
			
			while(n % d == 0)n /= d;
		}
	}
	
	if(n != 1){
		cnt++;
		f = n;
	}
	
	if(cnt > 1)printf("1\n");
	else printf("%lld\n", f);
	
	
	return 0;
}