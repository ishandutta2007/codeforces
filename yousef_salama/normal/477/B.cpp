#include <bits/stdc++.h>
using namespace std;

int n, k;
int main(){
	scanf("%d %d", &n, &k);

	printf("%d\n", k * (n * 6 - 1));
	for(int i = 0; i < n; i++)
		printf("%d %d %d %d\n", k * (i * 6 + 1), k * (i * 6 + 2), k * (i * 6 + 3), k * (i * 6 + 5));
	return 0;
}