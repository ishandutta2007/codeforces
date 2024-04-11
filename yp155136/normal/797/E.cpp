#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;
const int MAX_K = 316;

int n;
int a[MAX_N];
int dp[MAX_K][MAX_N];

int gao(int p,int k) {
	if (p>n) return 0;
	else if (k<MAX_K) {
		if (dp[k][p] == -1) return dp[k][p]=gao(p+a[p]+k,k)+1;
		else return dp[k][p];
	}
	else return gao(p+a[p]+k,k)+1;
}

int main() {
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for (int i=1;n>=i;i++) {
		scanf("%d",&a[i]);
	}
	int q;
	scanf("%d",&q);
	while (q--) {
		int p,k;
		scanf("%d %d",&p,&k);
		printf("%d\n",gao(p,k));
	}
}