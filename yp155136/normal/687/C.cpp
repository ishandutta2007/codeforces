#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 501;

bool dp[2][MAX_N][MAX_N];
int a[MAX_N];

//dp[i][j][k] ==> you can use first i to make j & make k

int main () {
	int n,K;
	while (scanf("%d %d",&n,&K) != EOF) {
		memset(dp,0,sizeof(dp));
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
		}
		dp[0][0][0] = 1;
		for (int i=1; n>=i; i++) {
			for (int j=0;K>=j;j++) {
				for (int k=0;K>=k;k++) {
					dp[i%2][j][k] = dp[(i-1)%2][j][k];
					if (j-a[i] >= 0) {
						dp[i%2][j][k] |= dp[(i-1)%2][j-a[i]][k];
						if (k - a[i] >=0) dp[i%2][j][k] |= dp[(i-1)%2][j-a[i]][k-a[i]];
					}
				}
			}
		}
		int cnt=1;
		vector<int> ans;
		for (int x=1;K>=x;x++) {
			if (dp[n%2][K][x] == true) ans.push_back(x);
		}
		printf("%d\n",cnt + ans.size());
		printf("0");
		for (auto i=ans.begin();i!=ans.end();i++) {
			printf(" %d", *i);
		}
		puts("");
	}
}