#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
	scanf("%d", &n);
	
	printf("%d\n", 3 * n + 4);
	
	printf("%d %d\n", 0, 0);
	printf("%d %d\n", 1, 0);
	printf("%d %d\n", 0, 1);
	
	for(int i = 1; i <= n; i++){
		printf("%d %d\n", i, i);
		printf("%d %d\n", i + 1, i);
		printf("%d %d\n", i, i + 1);
	}
	
	printf("%d %d\n", n + 1, n + 1);
	
	return 0;
}