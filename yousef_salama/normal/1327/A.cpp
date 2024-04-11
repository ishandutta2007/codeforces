#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		
		if(n < 1LL * k * k){
			printf("NO\n");
			continue;
		}
		
		if((k % 2 == 0) ^ (n % 2 == 0)){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	return 0;
}