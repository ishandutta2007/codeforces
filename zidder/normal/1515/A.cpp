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
	int x;
	cin >> x;
	vector<int> w(n);
	for (int &i: w) scanf("%d", &i);
	sort(w.begin(), w.end());
	vector<int> ans;
	for (int i=0;i<n;++i) {
		x -= w[i];
		ans.push_back(w[i]);
		if (x == 0) {
			ans.pop_back();
			if (i + 1 == n) {
				cout << "NO" << endl;
				return;
			}
			x -= w[i + 1];
			ans.push_back(w[i+1]);
			ans.push_back(w[i]);
			i++;
		}
	}
	cout << "YES" << endl;
	for (int i: ans) printf("%d ", i);
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