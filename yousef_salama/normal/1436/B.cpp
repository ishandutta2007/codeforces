#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(j > 0)printf(" ");
				
				if(i == j || i + 1 == j || i - 1 == j)printf("1");
				else printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}