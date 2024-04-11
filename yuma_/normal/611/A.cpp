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


int main() {
	int n; cin >> n;
	string st; cin >> st >> st;
	if (st == "week") {
		if (n == 5||n==6) {
			cout << 53 << endl;
		}
		else {

			cout << 52 << endl;
		}
	}
	else {
		if (n <= 28|| n == 29)cout << 12 << endl;
		else if (n==30) {
			cout << 11 << endl;
		}
		else {
			cout << 7 << endl;
		}
	}
	
	return 0;
}