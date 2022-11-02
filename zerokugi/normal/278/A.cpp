#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int n,d[105],s, a, b;
main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> d[i];
		s += d[i];
		d[i] += d[i-1];
	}
	cin >> a >> b;
	int dd = d[b-1] - d[a-1];
	if(dd<0) dd=-dd;
	cout << (dd < s-dd?dd:s-dd) << endl;
	return 0;
}