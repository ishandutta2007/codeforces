#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 106;

int cnt[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(cnt,0,sizeof(cnt));
		for (int i=1;n>=i;i++) {
			int x;
			scanf("%d",&x);
			cnt[x]++;
		}
		int ans=0;
		for (int i=0;MAX_N>i;i++) {
			while (cnt[i]) {
				cnt[i]--;
				int tmp=1;
				for (int j=i;MAX_N>j;j++) {
					while (cnt[j] && tmp<=j) {
						cnt[j]--;
						tmp++;
					}
				}
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}