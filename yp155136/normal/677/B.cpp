#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX_N = 1e5+6;

#define int long long

int a[MAX_N];
main () {
	int n,h,k;
	while (scanf("%I64d %I64d %I64d",&n,&h,&k) != EOF) {
		for (int x=1;n>=x;x++) scanf("%I64d",&a[x]);
		int ans=0;
		int sum=0;
		for (int x=1;n>=x;x++) {
//			if (sum>=h) {
//				ans += (sum/k);
//				sum%=k;
//			}
			if (sum+a[x]<=h) sum+=a[x];
			else {
				ans+=(sum/k);
				sum%=k;
				if (sum+a[x]>h) {
					ans++;
					sum=a[x];
				}
				else {
					sum+=a[x];
				}
				
			}
//			cout<<"x="<<x<<" , ans="<<ans<<endl;
		}
		ans += (sum/k) + (sum%k==0?0:1);
		printf("%I64d\n",ans);
	}
}