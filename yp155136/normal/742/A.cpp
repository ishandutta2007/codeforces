#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	while (cin >> n) {
		if (n==0) {
			puts("1");
			continue;
		}
		n%=4;
		if (n==0) n=4;
		int _=8;
		for (int i=1;n>i;i++) _*=8;
		cout<<_%10<<endl;
	}
}