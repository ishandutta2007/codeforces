#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	LL n,a,b,c;
	while (cin >> n >> a >> b >> c) {
		if (n>=b && a>b-c) {
			LL cnt=(n-c)/(b-c);
			n -= cnt*(b-c);
			cout<<n/a + cnt<<endl;
		}
		else cout<<n/a<<endl;
	}
}