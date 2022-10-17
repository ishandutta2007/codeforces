#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int &i: a) scanf("%d", &i);
    auto check = [&](int n, long long m) -> bool {
        long long cnt = 0;
        bool big=false;
        for (int i=0;i<k;++i) {
            if (a[i] >= 2 * m) {
                if ((a[i] / m) > 2) big = true;
                cnt += a[i] / m;
            }
        }
        if (n % 2) {
            return cnt >= n && big;
        } else {
            return cnt >= n;
        }
    };

    if (check(n, m) || check(m, n)) {
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