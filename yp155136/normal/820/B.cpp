#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main () {
	int n,a;
	cin >> n >> a;
	a*=n;
	int mnn=abs(180-a);
	int ans=1;
	for (int i=1;n-2>=i;i++) {
		if (abs(180*i-a) < mnn) {
			mnn = abs(180*i-a);
			ans=i;
		}
	}
	cout<<1<<' '<<ans+2<<' '<<ans+1<<endl;
}