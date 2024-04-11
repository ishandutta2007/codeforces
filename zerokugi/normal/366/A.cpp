#include <iostream>
#include <cstdio>
using namespace std;

int n, a, b, c, d;
main(){
	cin >> n;
	for(int i=1;cin >> a >> b >> c >> d;i++){
		if(min(a, b) + min(c, d) > n) continue;
		printf("%d %d %d\n", i, min(a, b), n-min(a, b));
		return 0;
	}
	puts("-1");
	return 0;
}