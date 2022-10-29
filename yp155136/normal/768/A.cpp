#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int a[n+2];
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		int i=2;
		while (n>=i && a[i]==a[i-1]) i++;
		int j=n-1;
		while (j>=1 && a[j]==a[j+1]) j--;
		printf("%d\n",max(j-i+1,0));
	}
}