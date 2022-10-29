#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long double ld;
const int MAX_N = 1e2 +6 ;

ld p[MAX_N];
ld dp[MAX_N];
ld _[MAX_N];

int main () {
	int n;
	cin >> n;
	for (int i=1;n>=i;i++) cin>> p[i];
	sort(p+1,p+n+1);
	ld ans = p[n];
	ld now = p[1];
	ld pre=(1-p[1]);
//	for (int i=2;n>=i;i++) {
//		now *= (1-p[i]);
//		now += (pre*p[i]);
//		pre *= (1-p[i]);
//		ans = max(ans,now);
//	}
//	for (int i=1;n>=i;i++) {
//		for(int j=i+1;n>=j;j++) {
//			ans = max(ans,p[i]*(1-p[j])+p[j]*(1-p[i]));
//		}
//	}
//	for (int i=1;n>=i;i++) {
//		for (int j=i+1;n>=j;j++) {
//			for (int k=j+1;n>=k;k++) {
//				ans = max(ans,p[i]*(1-p[j])*(1-p[k])+p[j]*(1-p[i])*(1-p[k])+p[k]*(1-p[i])*(1-p[j]));
//			}
//		}
//	}
//	dp[1] = p[1];
//	_[1] = 1-p[1];
//	for (int i=2;n>=i;i++) {
//		dp[i] = p[i];
//		_[i] = 1-p[i];
//		for (int j=1;i>j;j++) {
//			if (dp[j]*(1-p[i]) + _[j]*p[i] > dp[i]) {
//				dp[i] = dp[j]*(1-p[i]) + _[j]*p[i];
//				_[i] = _[j]*(1-p[i]);
//			}
//		}
//		ans = max(ans,dp[i]);
//	}
	now=0;
	pre=1;
	for (int qq=n;qq>=1;qq--) {
		now *= (1-p[qq]);
		now += (pre*p[qq]);
		pre *= (1-p[qq]);
		ans = max(ans,now);
		ld haha=now;
		ld pp = pre;
		for (int i=n-1;i>=1;i--) {
			haha *= (1-p[i]);
			haha += (pp*p[i]);
			pp *= (1-p[i]);
			ans = max(ans,haha);
		}
		break;
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
}