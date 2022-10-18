#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		
		vector <int> a(n), b(n), c(n);
		
		for(int i = 0; i < n; i++)scanf("%d", &a[i]);
		for(int i = 0; i < n; i++)scanf("%d", &b[i]);
		for(int i = 0; i < n; i++)scanf("%d", &c[i]);
		
		int prv = -1;
		for(int i = 0; i < n; i++){
			if(i > 0)printf(" ");
			
			if(i == 0){
				printf("%d", a[i]);
				prv = a[i];
			}else if(i != n - 1){
				if(a[i] != prv){
					prv = a[i];
				}else{
					prv = b[i];
				}
				printf("%d", prv);
			}else{
				if(a[i] != prv && a[i] != a[0]){
					prv = a[i];
				}else if(b[i] != prv && b[i] != a[0]){
					prv = b[i];
				}else{
					prv = c[i];
				}
				printf("%d", prv);
			}
		}
		printf("\n");
	}
	return 0;
}