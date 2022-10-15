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
	for (int &i: a) scanf("%d", &i);
	if (n%2 == 1) {
		cout << "Mike" << endl;
		return;
	}
	set<pair<int, int> > x;
	for (int i=0;i<n;++i) x.emplace(a[i], i);
	int ind = x.begin()->second;
	if (ind % 2 == 0) {
		cout << "Joe" << endl;
	} else {
		cout << "Mike" << endl;
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