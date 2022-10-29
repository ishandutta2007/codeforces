#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

typedef long double ld;
typedef long long LL;

const int MAX_N = 2e5 +6;

int a[MAX_N];

int main () {
	int n,k;
	while (cin >>n >> k) {
		for (int i=1;n>=i;i++) {
			cin >> a[i];
		}
		LL sum=0;
		for (int i=1;k>i;i++) {
			sum += a[i];
		}
		ld ans=0;
		for (int i=k;n>=i;i++) {
			sum += a[i];
			sum -= a[i-k];
			ans += ld(sum)/ld(n-k+1);
		}
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}
}