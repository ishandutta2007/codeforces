// https://codeforces.com/problemset/problem/1619/G

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n, k;
    cin >> n >> k;
    vector<pair<pair<int, int>, int> > a(n);
    for (int i=0;i<n;++i){
        scanf("%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second);
    }
    vector<int> parent(n, -1);
    map<int, set<pair<int, int> > > x_inds, y_inds;
    for (int i=0;i<n;++i){
        x_inds[a[i].first.first].emplace(a[i].first.second, i);
        y_inds[a[i].first.second].emplace(a[i].first.first, i);
    }

    vector<vector<int> > neighbours(n);

    for (int i=0;i<n;++i){
        auto &xst = x_inds[a[i].first.first];
        auto xit = xst.upper_bound(make_pair(a[i].first.second, i));
        if (xit != xst.end()){
            if (xit->first - a[i].first.second <= k) neighbours[i].push_back(xit->second);
        }
        xit--; // i
        if (xit != xst.begin()){
            xit--;
            if (a[i].first.second - xit->first <= k) neighbours[i].push_back(xit->second);
        }
        auto &yst = y_inds[a[i].first.second];
        auto yit = yst.upper_bound(make_pair(a[i].first.first, i));
        if (yit != yst.end()){
            if (yit->first - a[i].first.first <= k) neighbours[i].push_back(yit->second);
        }
        yit--; // i
        if (yit != yst.begin()){
            yit--;
            if (a[i].first.first - yit->first <= k) neighbours[i].push_back(yit->second);
        }
    }

    function<void(int, int)> dfs = [&](int v, int p){
        if (parent[v] == p) return;
        parent[v] = p;
        for (int u : neighbours[v]){
            dfs(u, p);
        }
    };

    for (int i=0;i<n;++i){
        if (parent[i] == -1) dfs(i, i);
    }

    map<int, int> par2det;

    for (int i=0;i<n;++i){
        int p = parent[i];
        if (par2det.find(p) == par2det.end()){
            par2det[p] = a[i].second;
        }
        else {
            par2det[p] = min(par2det[p], a[i].second);
        }
    }

    vector<int> dets;
    for (auto &p : par2det){
        dets.push_back(p.second);
    }

    sort(dets.begin(), dets.end());

    // cout << "det: " << endl;
    // for (int i:dets) cout << i << endl;
    // cout << ": det" << endl;

    int s = 0;
    int l=0, r=dets.size() - 1;
    while (l < r){
        while (dets[l] == s) l++;
        if (l >= r) break;
        r--;
        s++;
    }
    cout << s << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}