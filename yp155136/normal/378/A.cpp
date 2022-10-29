#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int a,b;
	while (cin >>a >> b) {
		int _=0,__=0;
		for (int i=1;6>=i;i++) {
			if (abs(a-i) < abs(b-i)) _++;
			else if(abs(a-i) == abs(b-i)) __++;
		}
		cout<<_<<' '<<__<<' '<<6-_-__<<endl;
	}
}