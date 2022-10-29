#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int t = n/7;
		int s=n%7;
		printf("%d %d\n",(2*t)+(s>=6?s-5:0),(2*t)+(s>=2?2:s));
	}
}