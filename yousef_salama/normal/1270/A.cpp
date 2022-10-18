#include <bits/stdc++.h>
using namespace std;

int t, n, k1, k2, ai;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &k1, &k2);
		
		bool ok = false;
		for(int i = 0; i < k1; i++){
			scanf("%d", &ai);
			if(ai == n)ok = true;
		}
		for(int i = 0; i < k2; i++)
			scanf("%d", &ai);
			
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}