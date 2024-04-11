#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &c);
		
		int res = 0;
		for(int x = 0; x <= a; x++)
		for(int y = 0; y <= b; y++){
			if(2 * x + y > b)continue;
			if(2 * y > c)continue;
			
			res = max(res, 3 * x + 3 * y);
		}
		printf("%d\n", res);
	}
	return 0;
}