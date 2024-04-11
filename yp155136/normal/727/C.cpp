#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 5004;

int ret[MAX_N];
int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		printf("? 1 2\n");
		fflush(stdout);
		scanf("%d",&ret[2]);
		printf("? 1 3\n");
		fflush(stdout);
		scanf("%d",&ret[3]);
		printf("? 2 3\n");
		fflush(stdout);
		scanf("%d",&ret[1]);
		a[1] = (ret[1] + ret[2] + ret[3])/2 - ret[1];
		for (int x=4;n>=x;x++) {
			printf("? 1 %d\n",x);
			fflush(stdout);
			scanf("%d",&ret[x]);
		}
		printf("! ");
		for (int x=1;n>=x;x++) {
			if (x==1) printf("%d",a[x]);
			else printf(" %d",ret[x] - a[1]);
		}
		puts("");
		fflush(stdout);
	}
}