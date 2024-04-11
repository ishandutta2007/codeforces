#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int a,b;
	while (cin >>a >>b) {
		if (a==0 && b==0) puts("NO");
		else if (0<=a-b&&a-b<=1 || 0<=b-a&&b-a<=1) puts("YES");
		else puts("NO");
	}
}