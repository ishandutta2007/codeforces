#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> x;
	for (int i = 0; i < 30; i++) {
		if ((n & (1 << i)))
			x.push_back(i + 1);
	}
	reverse(x.begin(), x.end());
	for (int y : x)
		printf("%d ", y);
	printf("\n");
}