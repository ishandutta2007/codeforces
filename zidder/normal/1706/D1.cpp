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
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    set<int> st(a.begin(), a.end());
    a = vector<int>(st.begin(), st.end());
    st.clear();
    int mnmm = a[0];
    for (int i: a) mnmm = min(mnmm, i);
    map<int, vector<pair<int, int> > > mp; // where -> who / who
    for (int i: a) mp[i/k].emplace_back(i, min(k, i+1));
    int ans = mp.rbegin()->first - mp.begin()->first;
    for (int mn=1;mn<=mnmm;++mn) {
        // remove mn-1
        for (auto &pr: mp[mn-1]) {
            // pr.first / pr.second
            if (pr.first / (pr.second - 1) >= mn) {
                mp[pr.first / (pr.second - 1)].emplace_back(pr.first, pr.second - 1);
            } else {
                mp[pr.first / (pr.first / mn)].emplace_back(pr.first, pr.first / mn);
            }
        }
        mp.erase(mn-1);
        // calc ans
        ans = min(ans, mp.rbegin()->first - mp.begin()->first);
    }
    cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}