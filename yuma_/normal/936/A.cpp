#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;



ld all_time;
ld on_time;
ld off_time;



int main() {
	cout<<setprecision(10)<<fixed;
	long long int k,d,t;cin>>k>>d>>t;
	if (k%d == 0) {
		cout<<t<<endl;
	}
	else {
		ld num = ld(k) / d;


		all_time=static_cast<long long int>(num+1)*d;
		on_time=k;
		off_time=all_time-on_time;

		ld time_value=on_time*2+off_time;

		long long int  need=static_cast<long long int>(2*t/time_value);

		ld rest=2*t-need*time_value;

		ld ans=need*all_time;

		if (rest > on_time * 2) {
			ans+=on_time+(rest-on_time*2);

		}
		else {
			ans+=rest/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}