#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

void out(int a, int b) {
	cout << 1 << " " << a << " " << b << endl;
}
int in() {
	string st; cin >> st;
	if (st == "TAK")return 1;
	else return 0;
}

int getone(const int l, const int r) {
	if (l + 1 == r)return l;
	else {
		int m = (l + r) / 2;
		if ((r-l) % 2) {
			out(m - 1, m + 1);
			if (in()) {
				getone(l, m+1);
			}
			else {
				getone(m, r);
			}
		}
		else {
			out(m - 1, m);
			if (in()) {
				getone(l, m);
			}
			else {
				getone(m, r);
			}
		}
		
	}
}

int main() {
	int N, K; cin >> N >> K;
	int num1=getone(1, N+1);
	int num2;
	if (num1 == 1) {
		num2 = getone(2, N + 1);
	}
	else if (num1 == N) {
		num2 = getone(1, N);
	}
	else {
		int numl = getone(1, num1);
		int numr = getone(num1 + 1, N + 1);
		if (numl == num1 - 1){
			if (numr == num1 + 1) {
				out(numl, numr);
				if (in()) {
					num2 = numl;

				}
				else {
					num2 = numr;
				}
			}
			else {
				num2 = numr;
			}
		}
		else {
			num2 = numl;
		}
	}
	cout << 2 << " " << num1 << " " << num2 << endl;

	return 0;
}