#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 4e5 + 6;

int a[MAX_N];
long long cnt[MAX_N];
int check[MAX_N];
long long pre[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(cnt,0,sizeof(cnt));
		memset(check,0,sizeof(check));
		memset(pre,0,sizeof(pre));
		long long sum=0;
		bool can=false;
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			sum += a[x];
			if (a[x] == 1) can = true;
			cnt[a[x]]++;
		}
		for (int x=1;MAX_N>x;x++) pre[x] = pre[x-1] + cnt[x];
		if (can) printf("%I64d\n",sum);
		else {
			long long ans = -1;
			for (int i=2;MAX_N/2>i;i++) {
				if (cnt[i]) {
					long long tmp=0;
					for (int j=i;MAX_N/2>j;j+=i) {
						tmp += j*(pre[j+i-1] - pre[j-1]);
					}
					ans = max(ans,tmp);
				}
			}
			printf("%I64d\n",ans);
		}
	}
}