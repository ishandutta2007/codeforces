#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n;
	while (scanf("%d",&n) != EOF) {
		if (n%2==0) puts("white\n1 2");
		else puts("black");
	}
}