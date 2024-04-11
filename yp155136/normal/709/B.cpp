#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 +6;

int a[MAX_N];

int main (){
	int n,b;
	while (scanf("%d %d",&n,&b) != EOF) {
		for (int x=0;n>x;x++) scanf("%d",&a[x]);
		sort(a,a+n);
		if (n==1) puts("0");
		else printf("%d\n",min(a[n-1]-a[1]+min(abs(b-a[1]),abs(b-a[n-1])),a[n-2]-a[0]+min(abs(b-a[0]),abs(b-a[n-2]))));
	}
}