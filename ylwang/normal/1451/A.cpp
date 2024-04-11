#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
using namespace std;
int read() {
	int x = 0; char c = ' ';
	for(; !isdigit(c); c = getchar()) ;
	for(; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
	return x;
}

signed main() {
	int T = read();
	while(T--) {
		int x = read();
		if(x == 1) printf("0\n");	
		else if(x == 2) printf("1\n");
		else if(x == 3) printf("2\n");
		else if(x & 1) printf("3\n");
		else printf("2\n");
	}
	return 0;
}