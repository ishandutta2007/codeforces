#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1006;

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) a[i] = i;
		int id=1;
		int sum=0;
		for (id=1;;id++) {
			sum += id;
			if (sum + (id+1) > n) break;
		}
		int tmp = n-sum;
		printf("%d\n",id);
		for (int i=1;id>=i;i++) {
			if (i!=1) printf(" ");
			if (i==id) printf("%d\n",a[i]+tmp);
			else printf("%d",a[i]);
		}
	}
}