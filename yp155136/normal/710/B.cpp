#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 3e5 + 6;

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF ) {
		for (int x=0;n>x;x++) scanf("%d",&a[x]);
		sort(a,a+n);
		if (n%2==0) printf("%d\n",a[n/2-1]);
		else printf("%d\n",a[n/2]);
	}
}