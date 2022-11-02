#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;


int x,y,a,b;
typedef int lli;
// 
lli gcd(lli a,lli b){
	return b>0?gcd(b,a%b):a;
}
// {
lli lcm(lli a,lli b){
	return a/gcd(a,b)*b;
}
main(){
	int i,j;
	while(cin >> x >> y >> a >> b){
		int ans;
		int z = lcm(x,y);
		cout << (b/z - (a-1)/z) << endl;
	}
	return 0;
}