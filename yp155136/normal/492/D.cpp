#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 6;

LL a[MAX_N];

int main () {
	int n;
	LL x,y;
	while (scanf("%d %I64d %I64d",&n,&x,&y) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&a[i]);
		}
		for (int i=1;n>=i;i++) {
			LL _=a[i];
			LL L=1,R=1e17;
			//find the number
			while (R-L!=1) {
				LL mid=(L+R)>>1;
				if (mid/x + mid/y >= _) R=mid;
				else L=mid;
			}
			//R probabaly is the answer
			if (R%x == 0 && R%y==0) puts("Both");
			else if (R%y==0) puts("Vanya");
			else puts("Vova");
		}
	}
}