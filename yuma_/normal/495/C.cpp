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
	string st; cin >> st;
	int lastshar;
	int leftnum=0;
	int rightnum=0;
	int shnum = 0;
	for (int i = 0; i <st.size(); ++i) {
		if (st[i] == '#') {
			lastshar = i;
			shnum++;
			rightnum++;
		}
		else if (st[i] == '(') {
			leftnum++;
		}
		else {
			rightnum++;
		}
	}
	if (leftnum < rightnum) {
		cout << -1 << endl;
		return 0;
	}
	else {
		int lastrightnum = 1 + leftnum - rightnum;

		vector<char>stack;
		for (int i = 0; i < st.size(); ++i) {
			if (st[i] == '(') {
				stack.push_back('(');
			}
			else if (st[i] == ')') {
				if (!stack.empty()&&stack.back() == '(') {
					stack.pop_back();
				}
				else {
					cout << -1 << endl;
					return 0;
				}
			}
			else {
				if (i == lastshar) {
					for (int j = 0; j < lastrightnum; ++j) {
						if (!stack.empty() && stack.back() == '(') {
							stack.pop_back();
						}
						else {
							cout << -1 << endl;
							return 0;
						}
					}
				}
				else {
					if (!stack.empty() && stack.back() == '(') {
						stack.pop_back();
					}
					else {
						cout << -1 << endl;
						return 0;
					}
				}
			}
		}
		for (int i = 0; i < shnum - 1; ++i) {
			cout << 1 << endl;
		}
		cout << lastrightnum << endl;
	}

	return 0;
}