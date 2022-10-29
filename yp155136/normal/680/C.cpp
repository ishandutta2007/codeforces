#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main () {
	int query[19] = {2,4,3,9,5,25,7,49,11,13,17,19,23,29,31,37,41,43,47};
	int result[19];
	for (int x=0;19>x;x++) {
		printf("%d\n",query[x]);
		fflush(stdout);
		char res[5];
		scanf("%s",res);
		if (strcmp(res,"yes") == 0) result[x]=1;
		else result[x]=0;
	}
	int cnt = 0;
	for (int x=0;19>x;x++) {
		if (result[x]==1) cnt++;
	}
	if (cnt>=2) puts("composite");
	else puts("prime");
}