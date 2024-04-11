#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;
int main () {
	int n,t;
	while (scanf("%d %d",&n,&t) != EOF) {
		double N=n, T=t;
		N*= pow(1.000000011,T);
		cout << fixed << setprecision(10) <<N << endl;
	}
}