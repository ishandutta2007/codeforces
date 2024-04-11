#include <bits/stdc++.h>
using namespace std;

int n, k;
int main(){
	scanf("%d %d", &n, &k);
	int l = 1, r = n, d = 0;
	while(l <= r){
		if(l != 1 || r != n)printf(" ");
		
		if(d % 2 == 0){
			printf("%d", l);
			l++;		
			d = min(d + 1, k - 1);		
		}else{
			printf("%d", r);
			r--;
			d = min(d + 1, k - 1);		
		}
	}
	printf("\n");

	return 0;
}