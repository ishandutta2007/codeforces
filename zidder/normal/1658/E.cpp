#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	vector<pair<int, pair<int, int> > > items(n*n);
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			int x;
			scanf("%d", &x);
			items.emplace_back(x, make_pair(i, j));
		}
	}

	sort(items.begin(), items.end());
	reverse(items.begin(), items.end());


	vector<string> s(n);
	string s1 = "";
	for (int i=0;i<n;++i){
		s1 += "G";
	}
	for (int i=0;i<n;++i) s[i] = s1;
	vector<vector<bool> > losing(n, vector<bool>(n, false));

	int mimin, mamin, mipl, mapl;
	mimin = -n;
	mamin = n;
	mipl = 0;
	mapl = 2 * n;

	for (int i=0;i<items.size();++i){
		auto p = items[i].second;
		if (p.first - p.second > mamin || p.first - p.second < mimin || p.first + p.second > mapl || p.first + p.second < mipl) continue;
		s[p.first][p.second] = 'M';
		mimin = max(mimin, p.first - p.second - k);
		mamin = min(mamin, p.first - p.second + k);
		mipl = max(mipl, p.first + p.second - k);
		mapl = min(mapl, p.first + p.second + k);
	}

	for (int i=0;i<n;++i){
		cout << s[i] << endl;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}