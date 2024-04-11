#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int a,b,c,d;
	while (cin >> a>> b >> c >> d) {
		if (b>=a) cout<<"Second"<<endl;
		else cout<<"First"<<endl;
	}
}