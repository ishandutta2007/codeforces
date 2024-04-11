#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	scanf("%d", &n);
	set<pair<int, int> > L, R;
	set<pair<pair<int, int>, int> > alll;
	for (int i=0;i<n;++i){
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		L.emplace(l, c);
		R.emplace(-r, c);
		alll.emplace(make_pair(l, r), c);
		int begin = L.begin()->first;
		int end = -R.begin()->first;
		int ans = 2 * 1000000000;
		auto it = alll.lower_bound(make_pair(make_pair(begin, end), 0));
		if (it->first == make_pair(begin, end)){
			ans = min(ans, it->second);
		}

		ans = min(L.begin()->second + R.begin()->second, ans);
		printf("%d\n", ans);
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}