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
    	vector <pair <int, int> > v;
    	int n;
    	scanf("%d", &n);
    	for (int i = 0; i < n; i++) {
    		int x, y;
    		scanf("%d %d", &x, &y);
    		v.push_back(make_pair(x, y));
    	}
    	bool ok = true;
    	for (int i = 0; i < n; i++) {
    		if (v[i].first < v[i].second) {
    			ok = false;
    			break;
    		}
    		if (i > 0) {
    			if (v[i].first < v[i - 1].first || v[i].second < v[i - 1].second) {
    				ok = false;
    				break;
    			}
    			if (v[i].first - v[i - 1].first < v[i].second - v[i - 1].second) {
    				ok = false;
    				break;
    			}
    		}
    	}
    	if (ok) {
    		printf("yes\n");
    	} else {
    		printf("no\n");
    	}
    }
	return 0;
}