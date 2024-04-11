#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int n;
    long long m;
    cin >> n >> m;
    vector<pair<int, int> > xp(n);
    for (int i=0;i<n;++i) scanf("%d%d", &xp[i].first, &xp[i].second);
    set<pair<pair<long long, int>, int> > st;
    for (int i=0;i<n;++i) {
        st.emplace(make_pair(xp[i].first - xp[i].second, i), -2);
        st.emplace(make_pair(xp[i].first + xp[i].second, i), -1);
        st.emplace(make_pair(xp[i].first, i), 0);
    }

    long long prvx = 0;
    long long val = 0;
    int cnt = 0;

    vector<pair<int, pair<long long, long long> > > v;
    vector<int> ans(n, 1);
    vector<int> qs(n);

    for (auto &pr: st) {
        val += (pr.first.first - prvx) * 1ll * cnt;
        if (pr.second == -2) {
            cnt++;
        } else if (pr.second == -1) {
            cnt++;
        } else {
            cnt -= 2;
            if (val > m) {
                v.push_back({pr.first.first, {val + pr.first.first, val - pr.first.first}});
            }
        }
        prvx = pr.first.first;
    }

    if (!v.empty()) {
        for (auto &pr: st) {
            if (pr.second == -1 && pr.first.first <= v.back().first) {
                ans[pr.first.second] = 0;
            }
            if (pr.second == -2 && pr.first.first >= v.front().first) {
                ans[pr.first.second] = 0;
            }
        }
    }

    auto it = st.begin();
    set<pair<long long, long long> > st1, st2;
    for (int vind=0;vind<v.size();++vind) {
        while (it!=st.end() && it->first.first <= v[vind].first) {
            int ind = it->first.second;
            if (it->second == -2) {
                st1.emplace(it->first.first, ind);
            } else if (it->second == -1) {
                st2.erase(make_pair(it->first.first, ind));
            } else {
                st1.erase(make_pair(xp[ind].first - xp[ind].second, ind));
                st2.insert(make_pair(xp[ind].first + xp[ind].second, ind));
            }
            ++it;
        }
        while (!st2.empty() && v[vind].second.first > m + st2.begin()->first) {
            ans[st2.begin()->second] = 0;
            st2.erase(st2.begin());
        }
        while (!st1.empty() && v[vind].second.second > m - st1.rbegin()->first) {
            ans[st1.rbegin()->second] = 0;
            st1.erase(*st1.rbegin());
        }
    }

    for (int i: ans) printf("%d", i);
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