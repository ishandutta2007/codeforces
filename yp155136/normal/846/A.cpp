#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 1e2 + 6;

int a[MAX_N];
int pre[3][MAX_N];

int main () {
	int n;
	scanf("%d",&n);
	for (int i=1;n>=i;i++) {
		scanf("%d",&a[i]);
		pre[a[i]][i] = pre[a[i]][i-1] + 1;
		pre[1-a[i]][i] = pre[1-a[i]][i-1];
	}
	int ans=0;
	for (int i=0;n>=i;i++) {
		ans = max(ans,pre[0][i] + pre[1][n] - pre[1][i]);
	}
	printf("%d\n",ans);
}