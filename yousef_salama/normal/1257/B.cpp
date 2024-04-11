#include <bits/stdc++.h>
using namespace std;

int T, x, y;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &x, &y);
		
		if(x == 2)x = 3;
		
		if(x > 3 || x >= y)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}