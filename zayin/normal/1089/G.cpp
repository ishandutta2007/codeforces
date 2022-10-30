#include<bits/stdc++.h>
using namespace std;

int k,a[14];

inline void solve() {
	scanf("%d",&k);
	int tot=0;
	for (int i=0;i<7;i++) scanf("%d",a+i),tot+=a[i];
	for (int i=0;i<7;i++) a[i+7]=a[i];
	int ans=(k-1)/tot;
	k-=ans*tot;
	int opt=1e9;
	ans*=7;
	for (int i=0;i<7;i++) {
		int tmp=0;
		for (int j=i;j<i+7;j++) {
			tmp+=a[j];
			if (tmp==k) {
				opt=min(opt,j-i+1+ans);
				break;
			}
		}
	}
	printf("%d\n",opt);
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) solve();
}