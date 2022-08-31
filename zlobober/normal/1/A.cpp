#include <iostream>
#include <cstdio>
using namespace std;

typedef long long llong;

int main()
{
	llong n, m, a;
	cin >> n >> m >> a;
	cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl	;
	return 0;
}