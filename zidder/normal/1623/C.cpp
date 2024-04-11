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
	vector<int> h(n);
	for (int i=0;i<n;++i){
		scanf("%d", &h[i]);
	}
	int l=0, r=h.back()+1;
	while (l + 1 < r){
		vector<int> h1 = h;
		int m = ((l + r) >> 1);
		bool ok = true;
		for (int i=n-1;i>=0;--i){
			if (h1[i] < m){
				ok = false;
				break;
			}
			if (i < 2) continue;
			int d = min((h1[i] - m) / 3, h[i] / 3);
			h1[i] -= 3 * d;
			h1[i-1] += d;
			h1[i-2] += d * 2;
		}
		if (ok){
			l = m;
		} else {
			r = m;
		}
	}
	cout << l << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}