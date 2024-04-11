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
    vector<int> a(n);
    vector<int> b(n);
    for (int &i: a) scanf("%d", &i);
    for (int &i: b) scanf("%d", &i);
    vector<pair<int, int> > moves;
    if (a[0] != b[0]) {
        cout << "NO" << endl;
        return;
    }
    // 1 2 4 3 1 2 1 1 -> 1 1 2 1 3 4 2 1 -> 
    //                    1 1 3 4 2 1 2 1
    for (int i=1;i<n;++i) {
        if (a[i] == b[i]) continue;
        for (int j=i;j<n;++j) {
            if (a[i-1] == a[j] && b[i] == a[j-1]) {
                moves.emplace_back(i, j+1);
                reverse(a.begin()+i, a.begin()+j);
                break;
            }
        }
        if (a[i] == b[i]) continue;
        map<int, int> right;
        set<int> lft;
        for (int j=i;j<n;++j) right[a[j]]++;
        int fnd = -1, j1;
        for (int j=i;j<n;++j) {
            if (a[i-1] == a[j-1] && b[i] == a[j]) {
                // find something including j
                if (!lft.empty()) {
                    fnd = *lft.begin();
                    j1 = j;
                    break;
                }
            }
            if (right[a[j]] == 1) {
                right.erase(a[j]);
                lft.erase(a[j]);
            }
            else {
                right[a[j]]--;
                lft.insert(a[j]);
            }
        }
        if (fnd != -1) {
            int mn=n + 1, mx=-1;
            for (int j=i;j<n;++j) {
                if (a[j] == fnd) {
                    mn = min(mn, j);
                    mx = max(mx, j);
                }
            }
            if (mn <= j1 && mx >= j1 && mn != mx) {
                moves.emplace_back(mn + 1, mx + 1);
                reverse(a.begin() + mn, a.begin() + mx + 1);
                i--;
                continue;
            }
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << moves.size() << endl;
    for (auto &p: moves) printf("%d %d\n", p.first, p.second);
    return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}