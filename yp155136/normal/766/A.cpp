#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	string a,b;
	while (cin >>a >> b) {
		if (a==b) puts("-1");
		else{
			printf("%d\n",max(a.size(),b.size()));
		}
	}
}