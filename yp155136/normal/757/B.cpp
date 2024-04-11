#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;

int cnt[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(cnt,0,sizeof(cnt));
		for (int i=1;n>=i;i++) {
			int t;
			scanf("%d",&t);
			cnt[t]++;
		}
		int ans=1;
		for (int i=2;MAX_N>i;i++) {
			int tmp=0;
			for (int j=i;MAX_N>j;j+=i) {
				tmp += cnt[j];
			}
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
}