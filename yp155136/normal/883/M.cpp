#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main () {
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if (x1 == x2 || y1 == y2) {
		cout<<abs(x1-x2)*2+abs(y1-y2)*2+4+2<<endl;
	}
	else {
		cout<<abs(x1-x2)*2+abs(y1-y2)*2+4<<endl;;;
	}
}