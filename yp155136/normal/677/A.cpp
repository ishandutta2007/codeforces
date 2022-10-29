#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main () {
	int n,h;
	while (scanf("%d %d",&n,&h) != EOF) {
		int sum=0;
		for (int x=0;n>x;x++) {
			int i;
			scanf("%d",&i);
			if (i<=h) sum++;
			else sum+=2;
		}
		printf("%d\n",sum);
	}
}