#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, k;
		scanf("%d %d", &n, &k);
		
		vector <int> a(n);
		bool found = false;
		
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			if(a[i] == k)found = true;
		}
		
		if(!found){
			printf("no\n");
			continue;
		}
		
		if(n == 1){
			printf("yes\n");
			continue;
		}
		
		if(n == 2){
			int cnt = (a[0] < k) + (a[1] < k);
			
			if(cnt == 0)printf("yes\n");
			else printf("no\n");
		
			continue;
		}
		
		bool ok = false;
		for(int i = 0; i < n - 2; i++){
			int cnt = (a[i] < k) + (a[i + 1] < k) + (a[i + 2] < k);
			if(cnt <= 1)ok = true;
		}
		
		if(ok)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}