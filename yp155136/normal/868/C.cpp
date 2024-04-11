#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 1e5 + 6;
const int MAX_K = 4;

int cnt[(1<<MAX_K)];

int main () {
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;n>=i;i++) {
		int num=0;
		for (int j=0;k>j;j++) {
			int x;
			scanf("%d",&x);
			num += (x<<j);
		}
		cnt[num]++;
	}
	bool can=false;
	for (int i=0;(1<<k)>i;i++) {
		for (int j=0;(1<<k)>j;j++) {
			if (cnt[i] &&cnt[j] && !(i&j)) can=true;
		}
	}
	if (can) puts("YES");
	else puts("NO");
}