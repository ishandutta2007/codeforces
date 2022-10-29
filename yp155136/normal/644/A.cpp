#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int n,a,b;
	while (scanf("%d %d %d",&n,&a,&b) != EOF) {
		if (a*b<n) puts("-1");
		else if (b%2==0){
			int sx=1;
			for (int x=1;a>=x;x++) {
				int id;
				if (x%2==1) id=1;
				else if (x%2==0)id=-1;
				if (x%2==1) sx=b*(x-1)+1;
				else sx=b*x;
				for (int y=1;b>=y;y++) {
					if (sx>n) printf("0");
					else printf("%d",sx);
					sx+=id;
					if (y!=b) printf(" ");
				}
				puts("");
			}
		}
		else {
			int sx=1;
			for (int x=1;a>=x;x++) {
				int id=1;
				for (int y=1;b>=y;y++) {
					if (sx>n) printf("0");
					else printf("%d",sx);
					sx+=id;
					if (y!=b) printf(" ");
				}
				puts("");
			}
		}
	}
}