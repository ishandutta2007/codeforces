#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 3e4 + 5;

int a[MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		for (int x=1;n-1>=x;x++) {
			scanf("%d",&a[x]);
		}
		int i=1;
		bool check=false;
		while (i!=n) {
			if (i==k) {
				check=true;
				break;
			}
			i+=a[i];
			if (i==k) {
				check=true;
				break;
			}
		}
		if (check) puts("YES");
		else puts("NO");
	}
}