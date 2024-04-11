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
    vector<pair<int, int> > lr(n);
    for (int i=0;i<n;++i) scanf("%d%d", &lr[i].first, &lr[i].second);
    int q;
    cin >> q;
    vector<int> anss(30);
    for (int k=0;k<30;++k) {
        vector<pair<int, int> > st; // (position, delta)
        for (int i=0;i<n;++i) {
            if ((lr[i].second - lr[i].first + 1) >= (1<<k)) {
                anss[k]++;
            } else {
                int ll = (lr[i].first - 1) % (1<<k) + 1;
                int rr = lr[i].second % (1<<k) + 1;
                if (ll < rr) {
                    st.emplace_back(ll, +1);
                    st.emplace_back(rr, -1);
                } else {
                    st.emplace_back(0, 1);
                    st.emplace_back(rr, -1);
                    st.emplace_back(ll, +1);
                }
            }
        }
        sort(st.begin(), st.end());
        int res = 0, answer = 0;
        for (auto &p: st) {
            // if (k == 2) cout << "P: " << p.first << " " << p.second << endl;
            res += p.second;
            answer = max(answer, res);
        }
        anss[k] += answer;
        // cout << k << " " << anss[k] << endl;
    }
    for (int i=0;i<q;++i){
        int w;
        scanf("%d", &w);
        for (int k=0;k<30;++k) {
            if (w&(1<<k)) {
                printf("%d\n", anss[k]);
                break;
            }
        }
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