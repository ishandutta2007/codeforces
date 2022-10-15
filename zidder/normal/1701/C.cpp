#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &i: a) scanf("%d", &i);

    auto bad = [&](int x) -> bool {
        vector<int> b(n);
        for (int i: a) b[i-1]++;
        long long c = 0, c1 = 0;
        for (int i: b) c += (x - min(i, x)) / 2;
        for (int i: b) c1 += (i - min(i, x));
        if (c >= c1) return false;
        return true;
    };

    int l = 0, r = 400000;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        if (bad(mid)) {
            // bad
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}