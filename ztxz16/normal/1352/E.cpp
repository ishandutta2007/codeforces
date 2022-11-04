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
    	int n;
    	scanf("%d", &n);
    	vector <int> v, exist(n + 1, 0);
    	for (int i = 0; i < n; i++) {
    		int x;
    		scanf("%d", &x);
    		v.push_back(x);
    	}

    	for (int l = 0; l < n; l++) {
    		int s = v[l];
    		for (int r = l + 1; r < n; r++) {
    			s += v[r];
    			if (s > n) {
    				break;
    			} else {
    				exist[s] = 1;
    			}
    		}
    	}
    	int ans = 0;
    	for (int l = 0; l < n; l++) {
    		ans += exist[v[l]];
    	}
    	printf("%d\n", ans);
    }
	return 0;
}