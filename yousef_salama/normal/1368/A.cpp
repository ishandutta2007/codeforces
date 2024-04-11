#include <bits/stdc++.h>
using namespace std;

int t, a, b, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &n);
		
		int c = 0;
		while(a <= n && b <= n){
			if(a >= b){
				b += a;
			}else{
				a += b;
			}
			c++;
		}
		printf("%d\n", c);
	}
	return 0;
}