#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


map<pair<pair<int, int>, int>, int> cache;

int ask(vector<int> x){
	sort(x.begin(), x.end());
	if (cache.find({{x[0], x[1]}, x[2]}) != cache.end())
		return cache[{{x[0], x[1]}, x[2]}];
	printf("? %d %d %d\n", x[0], x[1], x[2]);
	fflush(stdout);
	int res;
	cin >> res;
	if (res == -1){
		exit(0);
	}
	return cache[{{x[0], x[1]}, x[2]}] = res;
}

void answer(int i, int j){
	printf("! %d %d\n", i, j);
	fflush(stdout);
}

void solve(int test_ind){
	cache.clear();
	int n;
	cin >> n;
	auto update = [&](int &i, int &j, int k, int t){
		int a123 = ask({i, j, k});
		int a124 = ask({i, j, t});
		int a134 = ask({i, t, k});
		int a234 = ask({t, j, k});
		int a = max(a123, max(a124, max(a134, a234)));
		vector<int> cnt(4, 0);
		if (a == a123){
			cnt[0]++;
			cnt[1]++;
			cnt[2]++;
		}
		if (a == a124){
			cnt[0]++;
			cnt[1]++;
			cnt[3]++;
		}
		if (a == a134){
			cnt[0]++;
			cnt[2]++;
			cnt[3]++;
		}
		if (a == a234){
			cnt[1]++;
			cnt[2]++;
			cnt[3]++;
		}
		int c = max(cnt[0], max(cnt[1], max(cnt[2], cnt[3])));
		vector<int> ans;
		if (c == cnt[0]){
			ans.push_back(i);
		}
		if (c == cnt[1]){
			ans.push_back(j);
		}
		if (c == cnt[2]){
			ans.push_back(k);
		}
		if (c == cnt[3]){
			ans.push_back(t);
		}
		if (ans.size() == 1){
			i = ans[0];
			if (i == j) j = k;
		}
		else {
			i = ans[0];
			j = ans[1];
		}
	};

	int a = 1, b = 2;
	for (int i=3;i<n;i+=2){
		update(a, b, i, i + 1);
	}
	if (n%2){
		int o = 1;
		while (o == a || o == b) o++;
		update(a, b, n, o);
	}
	answer(a, b);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}