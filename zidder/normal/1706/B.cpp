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
    vector<int> c(n);
    for (int &i: c) scanf("%d", &i);
    map<int, vector<int>> inds;

    for (int i=0;i<n;++i) inds[c[i]].push_back(i);

    auto slv = [&](int col) {
        if (inds.find(col) == inds.end()) return 0;
        auto &v = inds[col];
        int odd = 0, even = 0, mx = 0;
        for (int i=v.size()-1;i>=0;--i) {
            if (i + 1 != v.size()) {
                if (v[i] % 2) {
                    odd = even + 1;
                } else {
                    even = odd + 1;
                }
                mx = max(mx, max(even, odd));
            } else {
                if (v[i] % 2) odd = 1;
                else even = 1;
                mx = 1;
            }
        }
        return mx;
    };

    for (int i=1;i<=n;++i) {
        printf("%d ", slv(i));
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