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
	vector<int> v(n);
	vector<int> cnt(31, 0);
	for (int i=0;i<n;++i) scanf("%d", &v[i]);
	for (int i=0;i<n;++i) for (int j=0;j<=30;++j){
		if ((1<<j)&v[i])cnt[j]++;
	}
	for (int k=1;k<=n;++k) {
		bool t=true;
		for (int j=0;j<cnt.size();++j)
			if (cnt[j]%k) t=false;
		if (t) cout << k << " ";
	}
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}