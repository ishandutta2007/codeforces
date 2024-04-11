#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	while (cin >>n) {
		int sum=0;
		int i;
		for (i=1;;i++) {
			sum += (i)*(i+1)/2;
			if (sum > n) break;
		}
		cout<<i-1<<endl;
	}
}