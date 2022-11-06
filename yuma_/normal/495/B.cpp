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
#include<cstdlib>
using namespace std;
vector<long long int> divisor(long long int n) {
	vector<long long int> res;
	for (long long int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	sort(begin(res), end(res));
	return res;
}

int main() {

	int aa, ab; cin >>aa >> ab;
	if (aa == ab) {
		cout << "infinity" << endl;
	}
	else if (aa < ab) {
		cout << "0" << endl;
	}
	else {
		int sa = abs(aa - ab);
		vector<long long int>div(divisor(sa));
		int ans = div.end()-upper_bound(div.begin(), div.end(), min(aa, ab)) ;
		cout << ans << endl;
	}
	return 0;
}