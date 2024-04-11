#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		long long sum=0;
		for (int i=1;n>=i;i++) {
			int a;
			scanf("%d",&a);
			sum += (a/k);
			sum += (a%k!=0);
		}
		printf("%I64d\n",(sum+1)/2);
	}
}