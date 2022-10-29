#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1e6 + 6;

int p[MAX_N];
int pos[MAX_N];

int main () {
	srand(time(NULL));
	int n,x;
	scanf("%d %d",&n,&x);
	if(n==1) {
		puts("YES");
		printf("%d\n",x);
	}
	else if (n==2) {
		if (x==0) {
			puts("NO");
		}
		else {
			puts("YES");
			printf("%d %d\n",0,x);
		}
	}
	else {
		int nn=(1<<19)-1;
		for (int i=0;nn>=i;i++) {
			p[i]=i;
		}
		puts("YES");
		while (true) {
			random_shuffle(p,p+(nn+1));
			int cnt=0;
			int id=0;
			for (int i=0;nn>=i;i++) {
				pos[p[i]] = i;
			}
			int now=0;
			for (int i=1;n-1>=i;i++) {
				now ^= p[i];
			}
			if (pos[(now^x)] <= n-1) continue;
			for (int i=1;n-1>=i;i++) {
				printf("%d ",p[i]);
			}
			printf("%d\n",(now^x));
			break;
		}
	}
}