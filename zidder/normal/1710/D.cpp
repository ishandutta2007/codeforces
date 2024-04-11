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
    vector<vector<bool> > v(n, vector<bool>(n));
    for (int i=0;i<n;++i) {
        string s;
        cin >> s;
        for (int j=0;j<i;++j) v[i][j] = v[j][i];
        for (int j=i;j<n;++j) v[i][j] = (s[j-i] == '1');
    }
    // 1 - 3
    // | 
    // 5 - 6 - 4 - 2

    vector<pair<int, int> > edges;
    function<void(int, int)> slv = [&](int l, int qr) {
        // if (test_ind == 1) cout << l << " " << qr << endl;
        int r = l;
        while (r + 1 < qr) {
            int pr = r;
            for (r=r+1;r<qr;++r) if (v[l][r]) break; // v[l][qr - 1] is always true
            // [l, pr] is connected [l, r] is connected
            if (v[pr+1][r]) {
                edges.emplace_back(l, r);
                // if [pr + 1, r] is connected and (0, r) can be an edge
                for (int j=r+1;j<qr;++j) {
                    if (v[pr+1][j]) r = j;
                }
                // [pr + 1, r] is connected as well
                slv(pr+1, r + 1);
            } else {
                int r2 = pr + 1;
                for (int j=r2+1;j<r;++j) {
                    if (v[pr+1][j]) r2 = j;
                }

                slv(pr+1, r2 + 1);
                edges.emplace_back(r, pr+1);
                while (r2 < r) {
                    int r3 = r2 + 1;
                    for (int j=r3+1;j<qr;++j) {
                        if (v[r2+1][j]) r3 = j;
                    }
                    slv(r2+1, r3+1);
                    edges.emplace_back(r2 + 1, l);
                    r2 = r3;
                }
                // cout << r << " rr2 " << r2 << endl;
                r = r2;
            }
        }
    };
    slv(0, n);

    for (auto &p: edges) cout << 1 + p.first << " " << 1 + p.second << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}