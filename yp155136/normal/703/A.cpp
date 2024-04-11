#include <iostream>
#include <stdio.h>
using namespace std;
int main (){
	int n;
	while (cin >>n) {
		int a[n],b[n];
		int w=0,l=0;
		for (int x=0;n>x;x++) {
			cin >> a[x] >> b[x];
			if (a[x]>b[x]) w++;
			else if (a[x]<b[x]) l++;
		}
		if (w>l) puts("Mishka");
		else if (w<l) puts("Chris");
		else puts("Friendship is magic!^^");
	}
}