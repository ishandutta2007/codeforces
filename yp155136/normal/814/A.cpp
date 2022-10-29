#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n,k;
	while (cin >> n >> k) {
		int a[n];
		for (int i=0;n>i;i++) cin >>a[i];
		int b[k];
		for (int i=0;k>i;i++) cin >>b[i];
		if (k>1) puts("Yes");
		else {
			for (int i=0;n>i;i++) {
				if (!a[i]) a[i] = b[0];
			}
			bool check=true;
			for (int i=1;n>i;i++) {
				check &= (a[i-1] < a[i]);
			}
			if (check) puts("No");
			else puts("Yes");
		}
	}
}