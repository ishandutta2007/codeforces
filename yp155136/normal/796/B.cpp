#include <iostream>
#include <stdio.h>
using namespace std;

bool haha[1000007];

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		for (int i=1;m>=i;i++) {
			int a;
			scanf("%d",&a);
			haha[a]=1;
		}
		int pos=-1;
		int now=1;
		if (haha[1] == 1) {
			puts("1");
			return 0;
			continue;
		}
		bool can=false;
		while (k--) {
			int a,b;
			scanf("%d %d",&a,&b);
			if (a==now || b==now) {
				if (a==now) now=b;
				else now=a;
			}
			if (haha[now] && !can) {
				pos=now;
				can=1;
			}
		}
		if (pos==-1) pos=now;
		printf("%d\n",pos);
	}
}