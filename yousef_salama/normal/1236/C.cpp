#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n; j++){
			if(j > 0)printf(" ");
			
			if(j % 2 == 0)printf("%d", i + j * n);
			else printf("%d", (j + 1) * n - i + 1);
		}
		printf("\n");
	}
	
	return 0;
}