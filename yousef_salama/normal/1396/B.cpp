#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int t, n, a[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		int s = 0, mx = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			
			s += a[i];
			mx = max(mx, a[i]);
		}
		
		if(s % 2 == 1)printf("T\n");
		else if(2 * mx > s)printf("T\n");
		else printf("HL\n");
	}
	
	return 0;
}