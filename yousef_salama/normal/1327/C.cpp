#include <bits/stdc++.h>
using namespace std;

int n, m, k, a, b;

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < k; i++)
		scanf("%d %d", &a, &b);
	for(int i = 0; i < k; i++)
		scanf("%d %d", &a, &b);
		
	printf("%d\n", (n - 1) + (m - 1) + n * m - 1);
	for(int i = 0; i < n - 1; i++)
		printf("U");
	for(int i = 0; i < m - 1; i++)
		printf("L");
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m - 1; j++){
			if(i % 2 == 0)printf("R");
			else printf("L");
		}
		if(i + 1 < n)printf("D");
	}
	printf("\n");
	
}