#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5+6;

int main () {
	int n,b,d;
	while (scanf("%d %d %d",&n,&b,&d) != EOF) {
		int tmp=0;
		int ans=0;
		for (int x=0;n>x;x++) {
			int i;
			scanf("%d",&i);
			if (i<=b) {
				tmp += i;
				if(tmp>d) {
					tmp=0;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}