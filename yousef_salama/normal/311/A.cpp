#include <bits/stdc++.h>
using namespace std;

int n, k;
int main(){
	scanf("%d %d", &n, &k);
	if(k >= n * (n - 1) / 2)printf("no solution\n");
	else{
		for(int x = 0; x < n; x++)
			printf("%d %d\n", x, x * 200000);
	}
	return 0;
}