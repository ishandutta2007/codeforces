#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
const int MOD = 1000000007;
void solve(int test_ind){
	int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    vector<int> ai(n);
    for (int i=0;i<n;++i) ai[a[i]] = i;
    int ans = 1;
    set<int> b;
    for (int i: a) b.insert(i);
    b.insert(n);
    int l = ai[0], r=ai[0];
    b.erase(0);
    auto A = [&](int n, int k) {
        int ns = 1;
        for (int i=0;i<k;++i) ns = (ns * 1ll * (n-i)) % MOD;
        return ns;
    };
    while (b.size() > 1) {
        int l1 = r - l + 1;
        int nxt = *b.begin();
        int ind = ai[nxt];
        if (ind > r) {
            while (r < ind) {
                r++;
                b.erase(a[r]);
            }
        } else {
            while (l > ind) {
                l--;
                b.erase(a[l]);
            }
        }
        int nxt2 = *b.begin();
        int l2 = r - l + 1;
        int dl = l2 - l1;
        // A[dl][nxt2 - nxt - 1]
        ans = ans * 1ll * A(n-b.size() - nxt, nxt2-nxt-1) % MOD;
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