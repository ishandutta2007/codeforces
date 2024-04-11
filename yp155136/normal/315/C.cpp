#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 2e5 +6;

LL a[MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%lld",&a[i]);
		}
		LL pre=0;
		LL _n=n;
		LL _i=2;
		for (int i=2;n>=i;i++) {
			LL d=pre - (_i-1)*(_n-_i)*a[i];
			if (d<k) {
				printf("%d\n",i);
				_n--;
			}
			else {
				pre += a[i] * (_i-1);
				_i++;
			}
		}
	}
}