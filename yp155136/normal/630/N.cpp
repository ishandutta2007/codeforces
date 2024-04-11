#include <iostream>
#include <cmath>
#include <iomanip>
#include <assert.h>
using namespace std;
int main () {
	double a,b,c;
	while (cin >> a >> b >> c) {
		double tmp=sqrt(b*b-4*a*c);
		if (a<0) {
			cout << fixed << setprecision(15)<< (-b-tmp)/(a*2) << endl;
			cout << fixed << setprecision(15)<< (-b+tmp)/(a*2)  << endl;
			continue;
		}
		cout << fixed << setprecision(15)<< (-b+tmp)/(a*2) << endl;
		cout << fixed << setprecision(15)<< (-b-tmp)/(a*2)  << endl;
	}
}