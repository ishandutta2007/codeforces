#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int ans = min(a, b - 1);
	ans = min(ans, c - 2);
	cout << 3 * (ans + 1) << endl;

	return 0;
}