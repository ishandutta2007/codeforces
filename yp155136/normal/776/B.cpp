#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5+6;

LL a[MAX_N];
int mx[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		if (n==1) {
			puts("1\n1");
			continue;
		}
		else if (n==2) {
			puts("1\n1 1");
			continue;
		}
		memset(a,-1,sizeof(a));
		n++;
		int ala=-1;
		for (LL i=2;n>=i;i++) {
			if (a[i]==-1) {
				for (LL j=i*i;n>=j;j+=i) {
					a[j]=0;
				}
			}
		}
		printf("2\n");
		for (int i=2;n>=i;i++) {
			if (i!=2) printf(" ");
			printf("%d",a[i]+2);
		}
		puts("");
	}
}