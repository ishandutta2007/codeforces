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
    	int n, value;
    	scanf("%d %d", &n, &value);
    	vector <int> v;
    	for (int i = 0; i < n; i++) {
    		int x;
    		scanf("%d", &x);
    		v.push_back(x);
    	}
    	sort(v.begin(), v.end());
    	reverse(v.begin(), v.end());
    	long long sum = 0;
    	int ans = 0;
    	for (int i = 0; i < n; i++) {
    		sum += v[i];
    		if ((long long)(i + 1) * value > sum) {
    			break;
    		}
    		ans++;
    	}
    	printf("%d\n", ans);
    }
	return 0;
}