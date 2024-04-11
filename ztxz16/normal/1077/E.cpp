#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
map <int, int> s;
vector <int> v;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		s[x]++;
	}
	
	for (map<int, int>::iterator it  = s.begin(); it != s.end(); ++it) {
		v.push_back(it->second);
	}
	
	sort(v.begin(), v.end());
	int ans = 0;
	for (int st = 1; st <= v.back(); st++) {
		int sum = 0, cur = st, pos = 0;
		while (pos < v.size() && cur <= v.back()) {
			pos = lower_bound(v.begin() + pos, v.end(), cur) - v.begin();
			sum += cur;
			cur += cur;
			pos++;
		}
		
		ans = max(sum, ans);
	}
	
	printf("%d\n", ans);
	return 0;
}