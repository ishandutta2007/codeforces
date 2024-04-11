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
    // max_i max(2mn, min(ai, ai+1))
    int l = 1, r = 1000000001;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        vector<int> b = a;
        int c = 0;
        for (int i=0;i<n;++i) {
            if (b[i] * 2ll < m) {b[i] = m; c++;}
        }
        if (c > k) {
            r = m;
            continue;
        }
        int q = 0;
        for (int i=1;i<n;++i) {
            q = max(q, min(b[i], b[i-1]));
        }
        if (q >= m) {
            l = m;
            continue;
        }
        if (c == k) {
            r = m;
            continue;
        }
        for (int i=0;i<n;++i) {
            if (b[i] >= m) {q = m;c++;break;}
        }
        if (q >= m) {
            l = m;
            continue;
        }
        if (c + 1 < k) {
            l = m;
            continue;
        } else {
            r = m;
            continue;
        }
    }
    cout << l << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}