#include <bits/stdc++.h>
using namespace std;
 
int n, p;
 
int main() {
	scanf("%d%d", &n, &p);
	bool flg = 0;
	for(int i = 1; i <= 40; ++i) {
		n -= p;
		int len = 0, x = n;
		while(x) {
			++len;
			x -= x & -x;
		} 
		if(len <= i && n >= i) {
			flg = 1;
			printf("%d\n", i);
			break;
		}
	}
	if(!flg) puts("-1");
	return 0;
}