#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
using namespace std;

long long int getans(long long int n) {
	if (n <= 1)return 0;
	if (n == 2)return 1;
	if (n == 3)return 1;
	if (n == 4)return 1;
	if (n == 5)return 2;
	long long int num = 1;
	long long int count = 0;
	while (num <= n) {
		num *= 2;
		count++;
	}
	long long int ans = ((count-1)*(count - 2)) / 2;

	long long int anum = num/4;
	long long int acount = 0;
	while (num-1-anum<=n) {
		anum /= 2;
		acount++;
		if (anum == 0)break;
	}
	ans += acount;
	return ans;
}

int main() {
	long long int a, b; cin >> a >> b;
	int ans = getans(b);
	ans -= getans(a-1);
	cout << ans << endl;
	return 0;
}