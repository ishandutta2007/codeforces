// https://codeforces.com/problemset/problem/1575/L

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;

int ST[4 * 200001];

void update(int x, int val, int l=0, int r=-1, int v=1) {
    if (r == -1) r = n;
    if (l + 1 == r){
        ST[v] = max(val, ST[v]);
        return;
    }
    int m = (l + r) / 2;
    if (x < m) update(x, val, l, m, v * 2);
    else update(x, val, m, r, v * 2 + 1);
    ST[v] = max(ST[2 * v], ST[2 * v + 1]);
}

int query(int qr, int l=0, int r=-1, int v=1){
    if (r == -1) r = n;
    // ql to end
    if (l >= qr) return 0;
    if (l + r == 1){
        return ST[v];
    }
    if (r <= qr) return ST[v];
    int m = (l + r) / 2;
    return max(query(qr, l, m, v * 2), query(qr, m, r, v * 2 + 1));
}

void solve(int test_ind){
    cin >> n;
    vector<int> a(n);
    vector<vector<int> > inds(200001);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        inds[a[i]].push_back(i);
    }
    for (int i = 1; i <= 200000; i++) {
        vector<pair<int, int> > kv;
        for (int j = 0; j < inds[i].size(); j++) {
            if (inds[i][j] < i) continue;
            kv.emplace_back(inds[i][j] - i, 1 + query(inds[i][j] - i + 1));
        }
        for (auto &p: kv){
            // cout << i << " " << p.first << " " << p.second << endl;
            update(p.first, p.second);
        }
    }

    cout << query(200001) << endl;

    // i3 - i1 >= 2
    // i3 - 3 >= i1 - 1
    // i1 < i2 < ... < in
    // 0 < b - a <= ib - ia
    // ib - b >= ia - a
    // 0 1 1 3 0
    // (new) j - a[j] <= i - a[i] (old)
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}