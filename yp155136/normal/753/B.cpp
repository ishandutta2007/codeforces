#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 16;

bool used[MAX_N];

pii Q(int a,int b,int c,int d) {
	printf("%d%d%d%d\n",a,b,c,d);
	fflush(stdout);
	int x,y;
	scanf("%d %d",&x,&y);
	return make_pair(x,y);
}

int main () {
	int a[4];
	int id=0;
	for (int i=0;10>i;i++) {
		pii ret=Q(i,i,i,i);
		if (ret.first == 1) a[id++]=i;
	}
	for (int i=0;4>i;i++) {
		for (int j=0;4>j;j++) {
			for (int k=0;4>k;k++) {
				for (int l=0;4>l;l++) {
					if (i==j||i==k||i==l||j==k||j==l||k==l) continue;
					pii ret=Q(a[i],a[j],a[k],a[l]);
					if (ret.first==4) return 0;
				}
			}
		}
	}
}