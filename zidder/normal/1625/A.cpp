#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, l;
	cin >> n >> l;
	vector<int> v(l);
	for (int i=0;i<n;i++){
		int x;
		cin >> x;
		for (int j=0;j<l;++j){
			v[j] += (x&(1<<j)) != 0;
		}
	}

	int ans = 0;
	for (int i=0;i<l;++i){
		if (v[i] * 2 > n)
			ans |= (1<<i);
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