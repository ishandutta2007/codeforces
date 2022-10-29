#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 1e5 + 6;
int a[MAX_N];
vector<int> v;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		v.clear();
		for (int x=0;n>x;x++) {
			scanf("%d",&a[x]);
			v.push_back(a[x]);
		}
		sort(v.begin(),v.end());
		int q;
		scanf("%d",&q);
		while (q--) {
			int t;
			scanf("%d",&t);
			int ans= lower_bound(v.begin(),v.end(),t+1) - v.begin();
			printf("%d\n",ans);
		}
	}
}