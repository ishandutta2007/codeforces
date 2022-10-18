#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		bool ok = true;
		int prv = 1 << 30;
		
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			
			if(a >= prv)ok = false;
			prv = a;
		}
		
		if(ok)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}