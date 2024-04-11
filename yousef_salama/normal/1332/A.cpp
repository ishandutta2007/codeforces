#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, d, x, y, xl, yl, xr, yr;

bool can(int x, int xl, int xr, int a, int b){
	if(xl == xr){
		if(a == 0 && b == 0)return true;
		else return false;
	}else{
		if(a == b)return true;
		else if(a > b){
			if(x - (a - b) >= xl)return true;
			else return false;
		}else{
			if(x + (b - a) <= xr)return true;
			else return false;
		}
	}
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		scanf("%d %d %d %d %d %d", &x, &y, &xl, &yl, &xr, &yr);
		
		if(can(x, xl, xr, a, b) && can(y, yl, yr, c, d))printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}