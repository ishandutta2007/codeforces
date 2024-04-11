#include <bits/stdc++.h>
using namespace std;

int a, b, c, n, xi;
int main(){
	scanf("%d %d %d %d", &a, &b, &c, &n);

	int r = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &xi);
		if((xi > b) && (c > xi))r++;
	}
	printf("%d\n", r);

	return 0;
}