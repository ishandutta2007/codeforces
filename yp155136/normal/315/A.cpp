#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e2 + 6;

bool can[MAX_N];
int a[MAX_N],b[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(can,0,sizeof(can));
		for (int i=1;n>=i;i++) {
			scanf("%d %d",&a[i],&b[i]);
		}
		for (int i=1;n>=i;i++) {
			for (int j=1;n>=j;j++) {
				if (i==j) continue;
				if (b[i] == a[j]) can[j]=1;
			}
		}
		int cnt=0;
		for (int i=1;n>=i;i++) {
			cnt += can[i];
		}
		printf("%d\n",n-cnt);
	}
}