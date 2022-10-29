#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 106;

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int id=0;
		int sum=0;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			//if (a[i]) id=i;
			sum += a[i];
			if (sum) id=i;
		}
		if (sum!=0) {
			puts("YES");
			puts("1");
			printf("1 %d\n",n);
			continue;
		}
		if (n==1) {
			if (id==0) puts("NO");
			else printf("1\n1 1\n");
			continue;
		}
		if (id==0) {
			puts("NO");
			continue;
		}
		puts("YES");
		puts("2");
		printf("1 %d\n",id);
		printf("%d %d\n",id+1,n);
	}
}