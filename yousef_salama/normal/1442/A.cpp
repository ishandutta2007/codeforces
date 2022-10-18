#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		int x, y;
		bool ok = true;
		
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			
			if(!ok)continue;
			
			if(i == 0){
				x = a;
				y = 0;
			}else{
				if(x + y == a)continue;
				if(x + y < a){
					y += a - (x + y);
				}else{
					x -= (x + y) - a;
					if(x < 0)ok = false;
				}
			}
		}
		
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}