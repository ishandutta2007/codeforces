/*
 * d.cpp
 *
 *  Created on: 2012-3-4
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int ans = INT_MIN;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			{
				int a = i, k = n / a;
				if (k >= 3) {
					vector<int> sum(a);
					for (int j = 0; j < n; ++j) {
						sum[j % a] += v[j];
					}
					ans = max(ans, *max_element(sum.begin(), sum.end()));
				}
			}
			{
				int a = n / i, k = n / a;
				if (k >= 3) {
					vector<int> sum(a);
					for (int j = 0; j < n; ++j) {
						sum[j % a] += v[j];
					}
					ans = max(ans, *max_element(sum.begin(), sum.end()));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}