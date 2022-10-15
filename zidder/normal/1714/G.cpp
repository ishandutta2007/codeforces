#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
    int n;
    cin >> n;
    vector<vector<pair<int, pair<int, int> > > > g(n);
    for (int i=1;i<n;++i) {
        int p;
        int a, b;
        scanf("%d%d%d", &p, &a, &b);
        g[p-1].push_back({i, {a, b}});
    }

    vector<int> r(n);
    function<void(int, long long, long long, vector<long long> &)> dfs = [&](int v, long long a, long long b, vector<long long>& B) {
        for (auto &p: g[v]) {
            long long a1 = a + p.second.first;
            long long b1 = b + p.second.second;
            B.push_back(b1);
            r[p.first] = upper_bound(B.begin(), B.end(), a1) - B.begin();
            dfs(p.first, a1, b1, B);
            B.pop_back();
        }
    };
    vector<long long> b = {};
    dfs(0, 0ll, 0ll, b);
    for (int i=1;i<n;++i) printf("%d ", r[i]);
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