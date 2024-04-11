#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int a,b,c,d,e,f;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		for (int i=b;i>=a;i--) {
			int _=n-i;
			if (c+e <= _ && _ <= d+f) {
				printf("%d",i);
				if (e <= _-d && _-d <= f) {
					printf(" %d %d\n",d,_-d);
				}
				else {
					;printf(" %d %d\n",_-e,e);
				}
				break;
			}
		}
	}
}