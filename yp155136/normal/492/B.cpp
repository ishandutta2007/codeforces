#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long double ld;
const int MAX_N = 1006;

double a[MAX_N];

int main () {
	int n,L;
	while (cin >> n >> L) {
		for (int i=1;n>=i;i++) {
			cin >>a[i];
		}
		sort(a+1,a+n+1);
		ld l=0.0,r=1e9+7;  //r is the answer
		int cnt=2000;
		while (cnt--) {
			ld mid = (l+r)/2.0;
			if (a[1] - mid >0 || a[n]+mid < L) {
//				cout<<"mid = "<<mid<<" , in!\n";
				l=mid;
				continue;
			}
			ld now=a[1] + mid;
			bool can=true;
			for (int i=2;n>=i;i++) {
				if (a[i]-mid > now) {
					can=false;
					break;
				}
				now = a[i] + mid;
			}
			if (can) r=mid;
			else l=mid;
		}
		cout<<fixed<<setprecision(20)<<r<<endl;
	}
}