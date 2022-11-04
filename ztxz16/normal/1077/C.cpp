#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1000005];
vector <int> v;

int main() {
	scanf("%d", &n);
	long long sum = 0;
	map <long long, int> s;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[a[i]]++;
		sum += a[i];
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		s[a[i]]--;
		sum -= a[i];
		
		if (sum % 2 == 0) {
			if (s[sum / 2] > 0) {
				v.push_back(i);
			}
		}
		
		s[a[i]]++;
		sum += a[i];
	}
	
	printf("%d\n", v.size());
	for (int i : v) {
		printf("%d ", i);
	}
	
	return 0;
}