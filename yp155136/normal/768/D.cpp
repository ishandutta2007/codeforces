#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e3 + 6;
const int MAX_D = 1e4 + 6;
const long double eps = 1e-9;

long double dp[MAX_D][MAX_N];
int ans[MAX_N];

int main () {
	int k,q;
	while (scanf("%d %d",&k,&q) != EOF) {
		dp[1][1] = 1.0;
		for (int i=2;MAX_D>i;i++) {
			for (int j=1;k>=j;j++) {
				dp[i][j] = (dp[i-1][j] * (double(j)/k)) + ((dp[i-1][j-1]*(double(k-j+1)/k)));
			}
		}
		while (q--) {
			int p;
			scanf("%d",&p);
			long double need=double(p)/2000.0;
			int L=0,R=MAX_D;
			while (R-L!=1) {
				int mid=(L+R)>>1;
//				cout<<"dp["<<mid<<"]["<<k<<"] = "<<dp[mid][k]<<endl;
				if (dp[mid][k] + eps >= need) R=mid;
				else L=mid;
			}
			printf("%d\n",R);
		}
	}
}