#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long long LL;

int main () {
	LL s,x1,x2,t1,t2,p,d;
	while (cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d) {
		LL s1,s2=abs(x1-x2);
		if (x2>x1) {
			if (d==-1) {
				s1=(p)+x1;
			}
			else if (p<=x1) {
				s1=x1-p;
			}
			else {
				s1 = 2*s-(p-x1);
			}
		}
		else {
			if (d==1) {
				s1 = s-p+(s-x1);
			}
			else if (p>=x1) {
				s1=p-x1;
			}
			else {
				s1 = 2*s-(x1-p);
			}
		}
		if (t1*(s1+s2)>=t2*s2) cout<<t2*s2<<endl;
		else cout<<t1*(s1+s2)<<endl;
	}
}