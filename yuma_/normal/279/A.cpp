
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
#include <assert.h>
#include <stdio.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()


int main() {
	//cout << 1 << endl;
	int x, y;
	cin >> x >> y;
	if (!x&&!y) {
		cout << x << endl; return 0;
	}
	int fx = 0;
	int fy = 0;
	for (int i = 1; i < 300; ++i) {
		int nx=fx + 2*i-1;
		int ny = fy;
		if (ny == y&&fx < x&&x <= nx) {
			cout << 4 * i - 4;
			break;
		}
		fx = nx;
		fy = ny;
		
		nx = fx;
		ny = fy +2 * i - 1;
		if (nx == x&&ny>= y&&y > fy) {
			cout << 4 * i - 3;
			break;
		}
		fx = nx;
		fy = ny;

		nx = fx - 2 * i ;
		ny = fy;
		if (ny == y&&fx > x&&x >= nx) {
			cout << 4 * i - 2;
			break;
		}
		fx = nx;
		fy = ny;

		 nx = fx;
		ny = fy -2 * i ;
		if (nx == x&&fy> y&&y >= ny) {
			cout << 4 * i - 1;
			break;
		}
		fx = nx;
		fy = ny;
	}
	cout << endl;
	return  0;
}