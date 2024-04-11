#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	string t;
    int n;
    cin >> t >> n;
    vector<string> s(n);
    for (int i=0;i<n;++i) cin >> s[i];
    int cr = 0;
    vector<pair<int, int> > ans;
    for (int i=0;cr<t.size();) {
        pair<int, int> cur = {-1, -1};
        int ncr = cr;
        for (;i<=cr;++i){
            for (int j=0;j<n;++j) {
                string ts = t.substr(i, s[j].size());
                if (ts == s[j]) {
                    if (ncr < i + (int)s[j].size()){
                        ncr = i + s[j].size();
                        cur = {i, j};
                    }
                }
            }
        }
        if (ncr == cr) {
            cout << -1 << endl;
            return;
        }
        ans.push_back(cur);
        cr = ncr;
    }
    cout << ans.size() << endl;
    for (auto &p: ans) {
        cout << p.second + 1 << " " << p.first + 1 << endl;
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