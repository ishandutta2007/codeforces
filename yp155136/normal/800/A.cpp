#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

typedef long double ld;
typedef long long LL;
const int MAX_N = 1e5 +6;

LL a[MAX_N],b[MAX_N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,p;
	cin >>n >> p;
	bool can=false;
	ld ans=0.0;
	LL tot=0;
	for (int i=0;n>i;i++) {
		cin >> b[i] >> a[i];
		tot += b[i];
	}
	if(tot<=p) {
		puts("-1");
		return 0;
	}
	ld L=0,R=1e25;
	int cnt=300;
	while (cnt--) {
		ld mid=(L+R)/2.;
//		cout<<"mid = "<<mid<<endl;
		//we have mid seconds
		ld tot_can = mid*p;
		bool check=true;
		for (int i=0;n>i;i++) {
			ld need=b[i]*mid;
			if (need > a[i]) tot_can-=(need-a[i]);
			if (tot_can<0) {
				check=false;
				break;
			}
		}
//		cout<<"tpt_can = "<<tot_can<<endl;
		if (check) L=mid;
		else R=mid;
	}
	cout<<fixed<<setprecision(14)<<R<<endl;
}