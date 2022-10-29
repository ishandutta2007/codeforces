#include <iostream>
#include <stdio.h>
using namespace std;

#define int long long
const int MAX_N = 1e5 + 6;
int row[MAX_N];
int col[MAX_N];

main () {
	int n,m;
	while (scanf("%I64d %I64d",&n,&m) != EOF) {
		int r=0,c=0;
		for (int x=0;m>x;x++) {
			if (x!=0) printf(" ");
			int i,j;
			scanf("%I64d %I64d",&i,&j);
			if (row[i]==0) {
				row[i]=1;
				r++;
			}
			if (col[j]==0) {
				col[j]=1;
				c++;
			}
			printf("%I64d",n*n-(c*n + r*n) + c*r);
		}
		puts("");
	}
}