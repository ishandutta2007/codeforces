#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, k;
		scanf("%d %d", &n, &k);
		
		vector <int> a(n);
		
		int c = 1;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			if(i > 0 && a[i] > a[i - 1])c++;
		}
			
		if(c == 1){
			printf("1\n");
			continue;
		}
		
		if(k == 1){
			printf("-1\n");
			continue;
		}
		
		printf("%d\n", (c + k - 3) / (k - 1));
	}
	return 0;
}