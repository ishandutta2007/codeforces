#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 200005;

bool ST[4*N];

int n;
void flip(int ql, int qr, int l=0, int r=-1, int v=1){
    if (r == -1) r = n;
    if (ql>=r || qr<=l) return;
    if (ql <= l && qr>=r) {ST[v] = !ST[v];return;}
    int m = (l + r) / 2;
    flip(ql, qr, l, m, 2*v);
    flip(ql, qr, m, r, 1+2*v);
}

bool gett(int ind, int l=0, int r=-1, int v=1) {
    if (r == -1) r = n;
    if (l + 1 == r) return ST[v];
    int m = (l + r) / 2;
    if (ind < m) return ST[v] ^ gett(ind, l, m, 2*v);
    else return ST[v] ^ gett(ind, m, r, 2*v+1);
}

void solve(int test_ind){
    cin >> n;
    for (int i=0;i<4*n;++i) ST[i] = false;
    string s1, s2;
    cin >> s1 >> s2;
    set<int> inds;
    for (int i=1;i<n-1;++i) {
        if (s1[i-1] != s1[i+1]) {
            inds.insert(i);
        }
    }
    if (s1[0] != s2[0] || s1.back() != s2.back()) {
        cout << -1 << endl;
        return;
    }
    for (int i=1;i<n-1;++i) {
        if (s1[i] == '1') {
            flip(i, i+1);
        }
    }

    long long ans = 0;
    int l = 1;
    while (l < n-1) {
        if (gett(l) == (s2[l] == '1')) {
            inds.erase(l);
            l++;
            continue;
        }
        if (inds.empty()) {
            cout << -1 << endl;
            return;
        }
        ans += *inds.begin() - l + 1;
        flip(l, *inds.begin() + 1);
        if (inds.find(*inds.begin() + 1) == inds.end() && *inds.begin() != n - 2) {
            inds.insert(*inds.begin() + 1);
        } else {
            inds.erase(*inds.begin() + 1);
        }
        inds.erase(inds.begin());
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