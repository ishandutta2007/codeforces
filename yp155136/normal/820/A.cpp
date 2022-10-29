#include <iostream>
#include <stdio.h>
using namespace std;

#define int long long

main () {
	int c,v0,v1,a,l;
	cin >> c >> v0 >> v1 >> a >> l;
	if (c==v0) {
		puts("1");
		return 0;
	}
	int now=v0;
	int ans=1;
	while (now < c) {
		ans++;
		v0 += a;
		if (v0 > v1) v0 = v1;
		//v0 -= l;
		//if (v0 > v1-l) v0=v1-l;
		now += v0-l;
	}
	cout<<ans<<endl;
}