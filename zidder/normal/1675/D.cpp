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
	vector<int> p(n);
	for (int i=0;i<n;++i) scanf("%d", &p[i]);
	int r = 0;
	for (int i=0;i<n;++i) if (--p[i]==i) r = i;
	vector<bool> leaf(n, true);
	for (int i=0;i<n;++i) if (i!=r) leaf[p[i]] = false;
	vector<bool> visited(n, false);
	vector<vector<int> > ans;
	for (int i=0;i<n;++i) if (leaf[i]) {
		vector<int> pth;
		for (int j=i;!visited[j];j=p[j]){
			visited[j] = true;
			pth.push_back(j);
		}
		reverse(pth.begin(), pth.end());
		ans.push_back(pth);
	}

	cout << ans.size() << endl;
	for (auto vv: ans) {
		cout << vv.size() << endl;
		for (int i: vv) cout << i + 1 << " ";
		cout << endl;
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