#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	int mx=0;
	cin >> n;
	int now=0;
	while (n--) {
		int a,b;
		cin >> a >> b;
		now-=a;
		now+=b;
		mx = max(mx,now);
	}
	cout<<mx<<endl;
}