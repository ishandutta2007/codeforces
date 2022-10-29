#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;

int last[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(last,-1,sizeof(last));
		bool can=true;
		for (int i=1;n>=i;i++) {
			int x,k;
			scanf("%d %d",&x,&k);
			if (last[k] + 1 == x) last[k]++;
			else if (last[k] >= x) ;
			else can=false;
		}
		if (can) puts("YES");
		else puts("NO");
	}
}