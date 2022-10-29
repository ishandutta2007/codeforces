#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	string a,b;
	while (cin >> a>> b) {
		cout<<a<<' '<<b<<endl;
		int n;
		cin >> n;
		while (n--) {
			string c,d;
			cin >> c >> d;
			if (a==c) {
				a=d;
			}
			else {
				b=d;
			}
			cout<<a<<' '<<b<<endl;
		}
	}
}