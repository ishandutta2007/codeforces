#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 262144;

LL cnt[MAX_N];

int main () {
	int n,x;
	while (scanf("%d %d",&n,&x) != EOF) {
		memset(cnt,0,sizeof(cnt));
		int mx=-1;
		for (int i=1;n>=i;i++) {
			int a;
			scanf("%d",&a);
			mx = max(mx,a);
			cnt[a]++;
		}
		LL ans=0;
		LL _=0;
		for (int i=0;MAX_N>i;i++) {
			if ((i^x) == i) _+=cnt[i]*(cnt[i]-1)/2;
			else ans += cnt[i]*cnt[i^x];
		}
		printf("%I64d\n",ans/2+_);
	}
}