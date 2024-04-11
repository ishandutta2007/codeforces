#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		
		int d = abs(a - b), r = 0;
		for( ; ; r++){
			if(d <= 0 && (d % 2 == 0))break;
			d -= r + 1;
		}
		printf("%d\n", r);
	}
	return 0;
}