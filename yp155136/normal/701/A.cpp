#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 103;
int a[MAX_N];
int b[MAX_N];

int main () {
	int n;
	while(scanf("%d",&n) != EOF) {
		int sum=0;
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			sum+=a[x];
		}
		(sum)=(sum*2)/n;
		memset(b,0,sizeof(b));
		for (int x=1;n>=x;x++) {
			if (b[x]==0) {
				b[x]=1;
				printf("%d ",x);
				for (int y=x+1;n>=y;y++) {
					if (a[x]+a[y]==sum && b[y]==0) {
						printf("%d\n",y);
						b[y]=1;
						break;
					}
				}
			}
		}
	}
}