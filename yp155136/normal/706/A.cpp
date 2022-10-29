#include <iostream>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX_N = 1e5+6;
int a[MAX_N]; 
int x[MAX_N];
int y[MAX_N];

int main () {
	double a,b;
	while (cin >>a >> b) {
		int n;
		cin >>  n;
		double best = 1e9 +7;
		for (int x=0;n>x;x++) {
			double i,j,v;
			cin >> i >>j>>v;
			best = min(best, sqrt((i-a) * (i-a) + (j-b)*(j-b)) / v);
		}
		cout << fixed<<setprecision(10)<<best<<endl;
	}
}