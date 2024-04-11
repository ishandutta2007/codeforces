#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 5006;

int cnt[MAX_N];
int dp[MAX_N][MAX_N];
int L[MAX_N];
int R[MAX_N];
bool used[MAX_N];

int meruru[MAX_N]; //end in i, max
int mxx[MAX_N]; //max[i] = max(meruru[1~i])
int a[MAX_N];

int main () {
	int n;
	scanf("%d",&n);
	for (int i=1;n>=i;i++) {
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		if (L[a[i]] == 0) L[a[i]]=i;
		R[a[i]] = i;
	}
	memset(dp,-1,sizeof(-1));
	for (int i=1;n>=i;i++) {
		int need_R = R[a[i]];
		memset(used,0,sizeof(used));
		int val=a[i];
		used[a[i]]=1;
		for (int j=i;n>=j;j++) {
			need_R = max(need_R,R[a[j]]);
			if (!used[a[j]]) {
				used[a[j]]=1;
				val ^= a[j];
			}
			if (L[a[j]] < i) break;
			if (j==need_R) {
				dp[i][j] = val;
			}
		}
	}
	for (int i=1;n>=i;i++) {
		for (int j=i;j>=1;j--) {
			if (dp[j][i] != -1) {
				meruru[i] = max(meruru[i],dp[j][i] + mxx[j-1]);
			}
		}
		mxx[i] = max(mxx[i-1],meruru[i]);
	}
	int ans=0;
	for (int i=1;n>=i;i++) {
		ans = max(ans,meruru[i]);
	}
	printf("%d\n",ans);
}