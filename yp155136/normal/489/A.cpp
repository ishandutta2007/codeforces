#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 3e3 + 6;

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=0;n>x;x++) {
			scanf("%d",&a[x]);
		}
		printf("%d\n",n);
		for (int i=0;n>i;i++) {
			int mn=a[i];
			int mn_id=i;
			for (int j=i+1;n>j;j++) {
				if (a[j] < mn) {
					mn = a[j];
					mn_id= j;
				}
			}
			swap(a[i],a[mn_id]);
			printf("%d %d\n",i,mn_id);
		}
	}
}