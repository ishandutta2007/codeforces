#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n,w;
	while (cin >>n >>w) {
		int a[n];
		int b[n];
		int tot=0;
		for (int i=0;n>i;i++) {
			cin >>a[i];
			b[i] = (a[i]+1)/2;
			tot += b[i];
		}
		if (tot>w) {
			puts("-1");
			continue;
		}
		while (tot < w) {
			int mx_a=-1;
			for (int i=0;n>i;i++) {
				if (a[i] > mx_a && b[i] != a[i]) {
					mx_a = a[i];
				}
			}
			for (int i=0;n>i;i++) {
				if (a[i] == mx_a && b[i]!=a[i]) {
					b[i]++;
					break;
				}
			}
			tot++;
		}
		for (int i=0;n>i;i++) {
			if (i) cout<<' ';
			cout<<b[i];
		}
		cout<<endl;
	}
}