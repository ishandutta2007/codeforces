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
    	long long n, base = 1;
    	cin >> n;
	    vector <long long> ans;
    	while (n > 0) {
    		if (n % 10 > 0) {
    			ans.push_back(n % 10 * base);
    		}
    		n /= 10;
    		base *= 10;
    	}
    	printf("%d\n", ans.size());
    	for (int i = 0; i < ans.size(); i++) {
    		printf("%d ", ans[i]);
    	}
    	printf("\n");
    }
	return 0;
}