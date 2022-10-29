#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;



int main () {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	const double eps = 1e-9;
	const double pi = 3.1415926535897932384626;
	double a,b,c,d;
	while (cin >> a >> b >> c >> d) {
		double r = a/2;
//		cout<<"r="<<r<<endl;
		double init = b * (r*r) * pi;
		double decrease = c / (r*r * pi);
//		cout<<"decrease = "<<decrease<<endl;
		double increase = d;
//		cout<<"increase = "<<increase<<endl;
		if (abs(decrease-increase)<=eps) {
			cout<<"NO\n";
		}
		else if (increase>decrease) {
			cout<<"NO\n";
		}
		else {
			cout<<"YES\n";
			cout<<fixed<<setprecision(10)<<b/(decrease-increase)<<endl;
		}
	}
}