#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
    cin >> n >> m;
    vector<vector<long long> > c(n, vector<long long>(m));
    for (auto &ci: c) for (long long &i: ci) scanf("%lld", &i);

    vector<long long> vals(n);

    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            vals[i] += c[i][j] * j;
        }
    }

    vector<pair<long long, int> > f;

    for (int i=0;i<n;++i) {
        f.emplace_back(vals[i], i);
    }

    sort(f.begin(), f.end());

    cout << f.rbegin()->second + 1 << " " << f.rbegin()->first - f.begin()->first << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}