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
	int n;
	scanf("%d", &n);
	int res = 0;
	for (int i = 2; i <= n; ++i) {
		int j = i;
		int count = 0;
		for (int l = 2; l * l <= j; ++l) {
			if (j % l == 0) {
				++count;
				while (j % l == 0)
					j /= l;
			}
		}
		if (j > 1) {
			++count;
		}
		if (count == 2) {
			++res;
		}
	}
	printf("%d\n", res);
	return 0;
}