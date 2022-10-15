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
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
	}
	bool ok = false;
	for (int i=1;i<n-1;++i){
		if (a[i] > 1) ok = true;
	}
	if (!ok){
		cout << -1 << endl;
		return;
	}

	set<int> odds;
	set<int> twos;
	for (int i=1;i<n-1;++i){
		if (a[i] > 1) twos.insert(i);
		if (a[i] % 2) odds.insert(i);
	}

	long long ans = 0;
	while (!odds.empty()){
		int ind = *twos.begin();
		if (*odds.begin() != ind){
			int q = *odds.begin();
			odds.erase(q);
			a[q]++;
			if (a[q] > 1) twos.insert(q);
			ans++;
			a[ind]-=2;
			if (a[ind] < 2) twos.erase(ind);
			continue;
		}
		if (*odds.rbegin() != ind){
			int q = *odds.rbegin();
			odds.erase(q);
			a[q]++;
			if (a[q] > 1) twos.insert(q);
			ans++;
			a[ind]-=2;
			if (a[ind] < 2) twos.erase(ind);
			continue;
		}
		if (twos.size() == 1){
			cout << -1 << endl;
			return;
		}
		ind = *twos.rbegin();
		if (*odds.begin() != ind){
			int q = *odds.begin();
			odds.erase(q);
			a[q]++;
			if (a[q] > 1) twos.insert(q);
			ans++;
			a[ind]-=2;
			if (a[ind] < 2) twos.erase(ind);
			continue;
		}
		if (*odds.rbegin() != ind){
			int q = *odds.rbegin();
			odds.erase(q);
			a[q]++;
			if (a[q] > 1) twos.insert(q);
			ans++;
			a[ind]-=2;
			if (a[ind] < 2) twos.erase(ind);
			continue;
		}
	}
	// cout << ans << endl;
	for (int i=1;i<n-1;++i){
		ans += a[i] / 2;
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