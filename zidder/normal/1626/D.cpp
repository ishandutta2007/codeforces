#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	vector<int> pc={0, 1};
	int p = a[0];
	for (int i=1;i<n;++i){
		if (a[i] > p){
			pc.push_back(i + 1);
			p = a[i];
		} else {
			pc[pc.size()-1]++;
		}
	}

    // 1 1 2 3 -> 2 3 4
	// 1 2 3 3 4 -> 1 2 4 5

	int ans = 10000000;
	for (int p1=0;p1<20;++p1){
		for (int p2=0;p2<20;++p2){
			for (int p3=0;p3<20;++p3){
				int ans1 = 0;
				int a1 = (1<<p1);
				auto it = upper_bound(pc.begin(), pc.end(), a1);
				it--; // leq a1
				ans1 += a1 - (*it);
				int a2 = (1<<p2) + (*it);
				it = upper_bound(pc.begin(), pc.end(), a2);
				it--; // leq a2
				ans1 += a2 - (*it);
				int a3 = (1<<p3);
				if (a3 < n - (*it)) continue;
				ans1 += a3 - (n - (*it));
				ans = min(ans, ans1);
			}
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}