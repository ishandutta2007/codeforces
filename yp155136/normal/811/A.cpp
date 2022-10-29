#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	LL x,y;
	while (cin >> x >> y) {
		LL now=1;
		LL step=0;
		while (1) {
			if (step&1) y-=now;
			else x-=now;
			now++;
			if (y<0 || x<0) break;
			step++;
		}
		if (y<0) puts("Valera");
		else puts("Vladik");
	}
}