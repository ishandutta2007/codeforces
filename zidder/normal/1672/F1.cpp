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
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    vector<vector<int> > v(n+1);
    for (int i=0;i<n;++i) {
        v[a[i]].push_back(i);
    }

    vector<pair<int, int> > lens;
    for (int i=0;i<=n;++i) {
        if (v[i].empty()) continue;
        lens.emplace_back((int)v[i].size(), i);
    }
    sort(lens.begin(), lens.end());

    vector<int> b(n);

    for (int i=0;i<lens.size();++i) {
        while (v[lens[i].second].size()) {
            for (int j=i;j<lens.size();++j) {
                int k = j + 1;
                int u = lens[j].second;
                if (k == lens.size()) k = i;
                b[v[u].back()] = lens[k].second;
                v[u].pop_back();
            }
        }
    }
    for (int i: b) printf("%d ", i);
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