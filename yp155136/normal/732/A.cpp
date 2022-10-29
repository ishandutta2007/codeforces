#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5 +6 ;

int main () {
	int a,b;
	while (cin >> a >> b) {
		for (int i=1;10>=i;i++) {
			if ((i*a)%10 == 0) {
				cout<<i;
				return 0;
			}
			else if ((i*a)%10 == b) {
				cout<<i;
				return 0;
			}
		}
	}
}