#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <cmath>

using namespace std;

const double eps = 0.0000000000000001;

double abs(double a,double b) {
	if (a>b) return a-b;
	else return b-a;
}

int main () {
	double x,y,z;
	string ans[12] = {
		"x^y^z",
		"x^z^y",
		"(x^y)^z",
		"(x^z)^y",
		"y^x^z",
		"y^z^x",
		"(y^x)^z",
		"(y^z)^x",
		"z^x^y",
		"z^y^x",
		"(z^x)^y",
		"(z^y)^x"
	};
	while (cin >> x >> y >> z) {
		//cout << x << ' ' << y << ' ' << z << endl;
		double a[12];
		bool check[12]={false};
		a[0]=z*log10(y)+log10(abs(log10(x))); if (log10(x)<0) check[0]=true;
		a[1]=y*log10(z)+log10(abs(log10(x))); if (log10(x)<0) check[1]=true;
		a[2]=log10(y*z)+log10(abs(log10(x))); if (log10(x)<0) check[2]=true;
		a[3]=log10(y*z)+log10(abs(log10(x))); if (log10(x)<0) check[3]=true;
		a[4]=z*log10(x)+log10(abs(log10(y))); if (log10(y)<0) check[4]=true;
		a[5]=x*log10(z)+log10(abs(log10(y))); if (log10(y)<0) check[5]=true;
		a[6]=log10(x*z)+log10(abs(log10(y))); if (log10(y)<0) check[6]=true;
		a[7]=log10(x*z)+log10(abs(log10(y))); if (log10(y)<0) check[7]=true;
		a[8]=y*log10(x)+log10(abs(log10(z))); if (log10(z)<0) check[8]=true;
		a[9]=x*log10(y)+log10(abs(log10(z))); if (log10(z)<0) check[9]=true;
		a[10]=log10(x*y)+log10(abs(log10(z)));if (log10(z)<0)check[10]=true;
		a[11]=log10(x*y)+log10(abs(log10(z)));if (log10(z)<0)check[11]=true;
		double max1=a[0];
		bool check1=check[0];
		int id=0;
		for (int i=1;11>=i;i++) {
			//cout <<fixed<<setprecision(50)<< "a[" << i <<"] = " << a[i] <<" : "<<check[i] <<endl;
			if (check1==false) {
				if (a[i]>max1&&abs(a[i]-max1)>eps && check[i]==false) {
					id=i;
					max1=a[i];
				}
			}
			else if (check1==true) {
				if (check[i]==false) {
					id=i;
					max1=a[i];
					check1=false;
				}
				else if (max1>a[i] && abs(max1-a[i]>eps)){
					id=i;
					max1=a[i];
				}
			}
		}
		cout << ans[id] << endl;
	}
}