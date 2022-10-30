#include <iostream>
#include <stdio.h>
using namespace std;

int x[123],y[123];

int main () {
	int n,a,b;
	cin >> n >> a >> b;
	for (int i=1;n>=i;i++) {
		cin >> x[i] >>y[i];
	}
	int mx=0;
	for (int i=1;n>=i;i++) {
		for (int j=1;n>=j;j++) {
			if (i==j) continue;
			if ((x[i] + x[j]) <= a && max(y[i],y[j]) <= b) {
				mx = max(mx,x[i]*y[i] +x[j]*y[j]);
			}
			if ((x[i] + x[j]) <= b && max(y[i],y[j]) <= a) {
				mx = max(mx,x[i]*y[i] +x[j]*y[j]);
			}
			if ((x[i] + y[j]) <= a && max(y[i],x[j]) <= b) {
				mx = max(mx,x[i]*y[i] +x[j]*y[j]);
			}
			if ((x[i] + y[j]) <= b && max(y[i],x[j]) <= a) {
				mx = max(mx,x[i]*y[i] +x[j]*y[j]);
			}
			if ((y[i] + y[j]) <= a && max(x[i],x[j]) <= b) {
				mx = max(mx,x[i]*y[i] +x[j]*y[j]);
			}
			if ((y[i] + y[j]) <= b && max(x[i],x[j]) <= a) {
				mx = max(mx,x[i]*y[i] +x[j]*y[j]);
			}
		}
	}
	cout<<mx<<endl;
}