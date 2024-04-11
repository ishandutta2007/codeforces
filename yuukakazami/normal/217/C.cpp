#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n;

int evoke(int a, int b, char op) {
	if (op == '|')
		return a | b;
	else if (op == '&')
		return a & b;
	else
		return a ^ b;
}

int VAL[4][2] = { { 0, 0 }, { 1, 1 }, { 0, 1 }, { 1, 0 } };

vector<bool> parse() {
	char ch = getchar();
	vector<bool> ret(3, false);
	//0:0/0
	//1:1/1
	//2:0/1
	if (ch == '0' || ch == '1') {
		ret[ch - '0'] = true;
		return ret;
	}
	if (ch == '?') {
		ret[2] = true;
		return ret;
	}
	//ch=='('
	vector<bool> lhs = parse();
	char op = getchar();
	vector<bool> rhs = parse();
	getchar(); //)
	for (int i = 0; i < 4; ++i)
		if (lhs[min(i, 2)]) {
			for (int j = 0; j < 4; ++j)
				if (rhs[min(j, 2)]) {
					int x = evoke(VAL[i][0], VAL[j][0], op);
					int y = evoke(VAL[i][1], VAL[j][1], op);
					if (x != y)
						ret[2] = true;
					else
						ret[x] = true;
				}
		}
	return ret;
}

int main() {
	cin >> n;
	scanf(" ");
	if (parse()[2])
		puts("YES");
	else
		puts("NO");
	return 0;
}