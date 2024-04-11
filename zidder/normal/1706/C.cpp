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
    for (int i=0;i<n;++i) scanf("%d", &a[i]);

    auto slv = [&](bool skip) -> long long {
        vector<long long> dp1(n+2);
        long long ans = 0;
        for (int i=1;i+1<n;i+=2) {
            ans += max(max(a[i-1] - a[i] + 1, a[i+1] - a[i] + 1), 0);
            dp1[i] = ans;
        }
        if (!skip) return ans;
        long long res = ans;
        ans = 0;
        for (int i=n-2;i-1>=0;i-=2) {
            ans += max(max(a[i-1] - a[i] + 1, a[i+1] - a[i] + 1), 0);
            if (i > 3) res = min(res, ans + dp1[i - 3]);
            else res = min(res, ans);
        }
        return res;
    };

    if (n%2) cout << slv(false) << endl;
    else cout << slv(true) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}