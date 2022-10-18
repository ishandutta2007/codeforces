#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		
		int sum = 0;
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			
			sum += a;
		}
		
		if(sum == m)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}