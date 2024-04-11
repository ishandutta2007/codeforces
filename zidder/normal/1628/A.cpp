#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int mex(map<int, int> &ms){
	for (int i=0;i<=ms.size();++i){
		if (ms.find(i) == ms.end())
			return i;
	}
}

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);

	map<int, int> ms;
	for (int i: a) ms[i]++;

	int ind = 0;
	vector<int> ans;
	while (ind < n){
		int mx = mex(ms);
		ans.push_back(mx);
		if (mx == 0){
			ms[a[ind]]--;
			if (ms[a[ind]] == 0){
				ms.erase(a[ind]);
			}
			ind++;
		}
		set<int> s;
		while(s.size() < mx){
			if (a[ind] < mx)
				s.insert(a[ind]);
			ms[a[ind]]--;
			if (ms[a[ind]] == 0){
				ms.erase(a[ind]);
			}
			ind++;
		}
	}
	cout << ans.size() << endl;
	for (int i: ans) cout << i << " ";
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