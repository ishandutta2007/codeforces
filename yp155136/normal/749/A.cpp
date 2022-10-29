#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		if (n==2 || n==3) {
			puts("1");
			printf("%d\n",n);
		}
		else if (n%2==0) {
			printf("%d\n",n/2);
			for (int i=1;n/2>=i;i++) {
				if (i!=1) printf(" ");
				printf("2");
			}
			puts("");
		}
		else if (n%2==1) {
			printf("%d\n",n/2);
			for (int i=1;n/2>i;i++) {
				if (i!=1) printf(" ");
				printf("2");
			}
			puts(" 3");
		}
	}
}