#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int gcd(int a,int b){
	return b>0?gcd(b,a%b):a;
}
int a,b,c,d;
main(){
	while(cin >> a >> b >> c >> d){
		if(c*b > d*a){
			swap(a, b);
			swap(c, d);
		}
		int x = (a*d-c*b);
		int y = (a*d);
		cout << x/gcd(x,y) << "/" << y/gcd(x,y) << endl;
	}
	return 0;
}