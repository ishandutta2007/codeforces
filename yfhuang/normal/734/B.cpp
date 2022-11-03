#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int k[4];

int main(){
	cin >> k[0] >> k[1] >> k[2] >> k[3];
	int x = min(k[0],min(k[2],k[3]));
	k[0] -= x;
	int ans = 256 * x;
	ans = ans + 32 * min(k[1],k[0]);
	cout << ans << endl;
	return 0;
}