// https://codeforces.com/problemset/problem/1605/D

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
    scanf("%d", &n);
    vector<int> left, right;
    vector<vector<int> > neigbours(n);
    for (int i=1;i<n;++i){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;--v;
        neigbours[u].push_back(v);
        neigbours[v].push_back(u);
    }

    vector<vector<int> > inds;
    int p = 1;
    for (int i=0;i<n;++i){
        if (i + 1 < p){
            inds.back().push_back(i);
        } else {
            p *= 2;
            inds.emplace_back();
            inds.back().push_back(i);
        }
    }

    function<void(int, int, bool)> dfs = [&](int u, int p, bool is_left){
        if (is_left){
            left.push_back(u);
        } else {
            right.push_back(u);
        }
        for (int v: neigbours[u]){
            if (v == p){
                continue;
            }
            dfs(v, u, !is_left);
        }
    };

    dfs(0, -1, true);

    if (left.size() > right.size()) swap(left, right);

    vector<int> ans(n);
    int lind = 0;
    for (int i=0;i<20;++i){
        if ((1<<i) & (int)left.size()){
            for (int j=0;j<(1<<i);++j){
                ans[left[lind++]] = inds[i][j];
            }
            inds[i].clear();
        }
    }
    int rind = 0;
    for (auto &v: inds){
        for (int j: v){
            ans[right[rind++]] = j;
        }
    }

    for (int i: ans){
        cout << i + 1 << " ";
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