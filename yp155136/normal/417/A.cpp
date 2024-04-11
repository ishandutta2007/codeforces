#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int c,d,n,m,k;
	while (cin >> c >> d >> n >> m >> k) {
		if (n*m - k <= 0) cout<<0<<endl;
		else {
			int need=n*m-k;
			int cnt=0;
			while (need) {
				if (need < n) {
					cnt += min(d*need,c);
					need=0;
				}
				else {
					cnt += min(d*n,c);
					need -= n;
				}
			}
			cout<<cnt<<endl;
			
		}
	}
}