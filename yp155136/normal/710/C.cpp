#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 50;

int a[MAX_N][MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int i=0,j=n/2;
		int tmp=0;
		int id=1;
		for (int x=0;n*n>x;x++) {
			a[i][j] = id++;
			tmp++;
			if (tmp==n) {
				i++;
				
				tmp=0;
			}
			else {
				i--;
				j++;
			}
			i=(i+n)%n;
			j=(j+n)%n;
		}
		for (int x=0;n>x;x++) {
			for (int y=0;n>y;y++) {
				if (y!=0) printf(" ");
				printf("%d",a[x][y]);
			}
			puts("");
		}
	}
}