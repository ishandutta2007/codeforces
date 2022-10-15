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
	int k;
	cin >> k;
	// a & n ^ a = 0
	// k & (n-1) + 0 & n^k = k
	map<int, int> mp;
	for (int i=0;i<n;++i){
		mp[i] = n-1-i;
	}
	if (k == n-1){
		if (n == 4){
			cout << -1 << endl;
			return;
		}
		mp[1] = n-3;
		mp[n-3] = 1;
		mp[2] = n-2;
		mp[n-2] = 2;
		mp[n-1] = n - 4;
		mp[n-4] = n - 1;
		mp[3] = 0;
		mp[0] = 3;
	}
	else {
		mp[k] = n-1;
		mp[n-1-k] = 0;
		mp[n-1] = k;
		mp[0] = n-1-k;
	}
	for (int i=0;i<n;++i){
		if (mp.find(i) == mp.end()) continue;
		int j = mp[i];
		mp.erase(i);
		mp.erase(j);
		printf("%d %d\n", i, j);
	}
	// a & b + (n^a)&(n^b) = n-1
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}