#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	while (cin >>n) {
		if (n%2==1) cout<<5<<endl;
		else {
			if (n<500)cout<<n+2<<endl;
			else cout<<n-2<<endl;
		}
	}
}