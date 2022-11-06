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
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()


bool f[1000001];

int main() {
	memset(f, false, sizeof(f));
	int a, m; cin >> a >> m;
	a %= m;
	while (1) {
		if (f[a]) {
			cout << "No" << endl;
			break;
		}
		else {
			f[a] = true;
			a *= 2;
			a %= m;
			if (a == 0) {
				cout << "Yes" << endl;
				break;
			}
		}
	}

	return 0;
}