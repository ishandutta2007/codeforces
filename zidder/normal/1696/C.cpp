#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    int k;
    scanf("%d", &k);
    vector<int> b(k);
    for (int &i: b) scanf("%d", &i);
    vector<pair<int, long long> > a1, b1;

    auto append = [&](int x, int y, vector<pair<int, long long> > &arr) {
        if (arr.empty()) {
            arr.emplace_back(x, y);
            return;
        }
        if (arr.back().first == x) {
            arr.back().second += y;
            return;
        }
        arr.emplace_back(x, y);
    };

    for (int i=0;i<n;++i) {
        int x = a[i];
        int y = 1;
        while (x % m == 0) {
            x /= m;
            y *= m;
        }
        append(x, y, a1);
    }
    for (int i=0;i<k;++i) {
        int x = b[i];
        int y = 1;
        while (x % m == 0) {
            x /= m;
            y *= m;
        }
        append(x, y, b1);
    }
    if (a1 == b1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}