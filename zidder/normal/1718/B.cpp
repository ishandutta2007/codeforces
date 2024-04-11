#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long f[100];

void solve(int test_ind){
	int k;
    cin >> k;
    vector<int> c(k);
    for (int &i: c) scanf("%d", &i);

    // 1 1 2 3 5 8
    // 11 6 3
    // 3 6 3
    // 3 1 3
    // 0 1 3
    // 0 1 1
    // 0 1 0
    long long cnt = 0;
    for (int i: c) cnt += i;
    int r = -1;
    for (int i=0;i<100;++i) {
        cnt -= f[i];
        if (cnt < 0) {
            cout << "NO" << endl;
            return;
        }
        if (cnt == 0) {
            r = i;
            break;
        }
    }
    // [0, r]
    set<pair<int, int> > cs;
    for (int i=0;i<k;++i) cs.emplace(c[i], i);
    int prev = -1;
    for (int i=r;i>=0;--i) {
        auto it = cs.rbegin();
        if (it->second == prev) it++;
        if (it == cs.rend() || it->first < f[i]) {
            cout << "NO" << endl;
            return;
        }
        pair<int, int> pr = *it;
        cs.erase(pr);
        cs.emplace(pr.first-f[i], pr.second);
        prev = pr.second;
    }
    cout << "YES" << endl;
}

int main(){
    f[0] = f[1] = 1;
    for (int i=2;i<100;++i) {
        f[i] = f[i-1] + f[i-2];
        if (f[i] > 10000000000ll) f[i] = -1;
    }
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}