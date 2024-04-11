#include <bits/stdc++.h>
using namespace std;

int k;

int main(){
	scanf("%d", &k);
	
	printf("2 3\n");
	printf("%d %d %d\n", (1 << 18) - 1, (1 << 17), (1 << 18) - 1);
	printf("%d %d %d\n", k, (1 << 18) - 1, (1 << 17) - 1);
	
	return 0;
}