#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

typedef vector<int> vi;

int main() {
	string s;
	cin >> s;
	int res = 0;
	int count = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			++count;
		if (s[i] == ')')
			--count;
		if (count < 0) {
			res -= count;
			count = 0;
		}
	}
	res += count;
	printf("%d\n", (int)s.size() - res);
	return 0;
}