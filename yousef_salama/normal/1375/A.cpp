#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int t, n, a[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++){
			if(i > 0)printf(" ");
			
			scanf("%d", &a[i]);
			printf("%d", abs(a[i]) * (i % 2 == 0 ? 1 : -1));
		}
		printf("\n");
	}
	return 0;
}