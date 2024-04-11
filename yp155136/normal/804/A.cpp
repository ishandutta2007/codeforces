#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	while (cin >> n) {
		if (n==1) puts("0");
		else if (n%2==0) {
			printf("%d\n",n/2-1);
		}
		else {
			printf("%d\n",(n-1)/2-1+1);
		}
	}
}