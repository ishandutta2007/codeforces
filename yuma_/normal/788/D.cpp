#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

void output(int x, int y) {
	printf("0 %d %d\n", x, y);
	fflush(stdout);
}
int input() {
	int d;
	scanf("%d", &d);
	if (d == -1)exit(0);
	return d;
}

const int L = 1e8;

int main() {
	vector<int>x_lines;
	vector<int>y_lines;
	int n =-L;
	int pre_dis = 3e8;
	int plus = 0;
	set<int>ns;
	while (n<=L) {
		output(n, n);
		int d = input();
		if (d < pre_dis) {
			x_lines.push_back(n + d);
			y_lines.push_back(n + d);
			ns.emplace(n + d);
			pre_dis = 1;
			plus = 1;
			n = n + d+1;
			if (n + 100 <= L) {
				output(n + 100, n + 100);
				int ad = input();
				if (ad == 101) {
					pre_dis = 202;
					plus = 202;
					n += 201;
				}
			}
		}
		else {
			assert(d == pre_dis);
			n += plus;
			pre_dis += plus;
			plus *= 2;
		}
	}
	int t = 0;
	for (int i = 0; i < 1e5; ++i) {
		if (ns.find(i) == ns.end()) {
			t = i;
			break;
		}
	}
	vector<int>x_anss,y_anss;
	for (auto a:x_lines) {
		output(a, t);
		if (!input()) {
			x_anss.emplace_back(a);
		}
	}
	for (auto a : y_lines) {
		output(t,a);
		if (!input()) {
			y_anss.emplace_back( a);
		}
	}
	printf("1 %d %d\n", x_anss.size(), y_anss.size());
	for (int i = 0; i < x_anss.size(); ++i) {
		printf("%d", x_anss[i]);
		if (i != x_anss.size() - 1)printf(" ");
		else printf("\n");
	}
	for (int i = 0; i < y_anss.size(); ++i) {
		printf("%d", y_anss[i]);
		if (i != y_anss.size() - 1)printf(" ");
		else printf("\n");
	}
	return 0;
}