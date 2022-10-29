#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5 +6;

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			while (a[i]%2==0) a[i]/=2;
			while (a[i]%3==0) a[i]/=3;
		}
		int _=a[1];
		bool can=true;
		for (int i=2;n>=i;i++) {
			can &= (_==a[i]);
		}
		if (can) puts("YES");
		else puts("NO");
	}
}