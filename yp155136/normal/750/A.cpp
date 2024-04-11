#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5 + 6;

int a[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		int t=240-m;
		int cnt=0;
		for (int i=5;n*5>=i;i+=5) {
			if (t<i) break;
			cnt++;
			t-=i;
		}
		printf("%d\n",cnt);
	}
}