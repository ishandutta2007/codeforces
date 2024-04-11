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
    sort(a.begin(), a.end());
    vector<int> b(m);
    for (int i=0;i<m;++i) {
        int j = (i + 1) % m;
        b[i] = (a[j] + n - a[i] - 1) % n;
        // cout << b[i] << endl;
    }
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i=m-1, c=0;i>=0;--i) {
        ans += max(b[i] - 1 - 4 * c, max(0, min(b[i] - 4*c, 1)));
        // cout << ans << endl;
        c++;
    }
    cout << n - ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}