#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main () {
	int a[101];
	int b[101];
	int n;
	scanf("%d",&n);
	for (int x=0;n>x;x++) {
		scanf("%d",&a[x]);
		b[x]=a[x];
	} 
	sort(a,a+n);
	for (int x=0;n>x;x++) {
		int id=x;
		for (int y=x;n>y;y++) {
			if (b[y]==a[x]) {
				id=y;
				break;
			}
		}
		for (int y=id;y>x;y--) {
			printf("%d %d\n",y,y+1);
			swap(b[y],b[y-1]);
		}
	}
}