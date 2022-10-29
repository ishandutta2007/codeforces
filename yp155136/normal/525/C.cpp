#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e6 + 6;

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
		LL tot=0;
		LL now=0;
		int _=0;
		for (LL i=MAX_N-1;i>=1;i--) {
			while (cnt[i] >= 2) {
				if (_) {
					tot += now*i;
					_=0;
					now=0;
				}
				else {
					now=i;
					_=1;
				}
				cnt[i]-=2;
			}
			if (cnt[i] && cnt[i-1]) {
				cnt[i]--;
				cnt[i-1]--;
				if (_) {
					tot += now*(i-1);
					_=0;
					now=0;
				}
				else {
					now = (i-1);
					_=1;
				}
				
			}
		}
		printf("%I64d\n",tot);
	}
}