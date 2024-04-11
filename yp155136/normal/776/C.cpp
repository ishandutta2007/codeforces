#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;

LL pre[MAX_N];
LL a[MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		map<LL,LL> mp;
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&a[i]);
			pre[i] = pre[i-1]+a[i];
			mp[pre[i]]++;
		}
		LL tmp=0;
		LL ans=0;
		for (int i=1;n>=i;i++) {
			//starting from pre
			LL ret=1;
			int cnt=55;
			while (abs(ret) <= 1e15+6) {
				ans += mp[ret+tmp];
				ret*=k;
				if (ret==1) break;
				else if (ret==-1) {
					ans += mp[ret+tmp];
					break;
				}
			}
			mp[pre[i]]--;
			tmp=pre[i];
		}
		printf("%I64d\n",ans);
	}
}