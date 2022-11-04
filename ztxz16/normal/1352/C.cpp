#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
    	long long n, k;
    	cin >> n >> k;
    	cout << ((k - 1) / (n - 1) * n) + (k - 1) % (n - 1) + 1 << endl;
    }
	return 0;
}