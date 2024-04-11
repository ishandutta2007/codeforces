#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 4;

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		LL sum=0;
		for (int x=0;n>x;x++) {
			int i;
			scanf("%d",&i);
			sum += (i-1);
			if (sum%2==0) puts("2");
			else puts("1");
		}
	}
}