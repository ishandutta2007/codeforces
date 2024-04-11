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
	map<int, vector<int> > a;
	for (int i=0;i<n;++i){
		int x;
		scanf("%d", &x);
		a[x].push_back(i);
	}

	int k = -1;
	for (auto &p: a){
		for (int i=1;i<p.second.size();++i){
			int k1;
			int a1 = p.second[i];
			int a2 = p.second[i-1];
			k1 = (n - a1) + a2;
			k = max(k1, k);
		}
	}
	cout << k << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}