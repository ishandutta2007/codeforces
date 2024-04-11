#include <iostream>
#include <stdio.h>

int v[10] = {6,2,5,5,4,5,6,3,7,6};

int f(int x) {
	int ret=0;
	while (x!=0) {
		int t=x%10;
		ret+=v[t];
		x/=10;
	}
	return ret;
}

int sum[1000002];


using namespace std;
int main () {
	sum[0]=v[0];
	for (int x=1;1000000>=x;x++) {
		sum[x] = sum[x-1] + f(x);
	}
	int a,b;
	while (scanf("%d %d",&a,&b) != EOF) {
		printf("%d\n",sum[b]-sum[a-1]);
	}
}