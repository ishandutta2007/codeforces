#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		int ans= -1;
		for (int x=0;n>x;x++) {
			int tmp=2147483647;
			for (int y=0;m>y;y++) {
				int t;
				scanf("%d",&t);
				if (t<tmp) tmp=t;
			}
			if (ans<tmp) ans=tmp;
		}
		printf("%d\n",ans);
	}
}