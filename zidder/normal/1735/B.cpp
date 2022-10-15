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
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i=1;i<n;++i) {
        int c = (2 * a[0] - 1);
        ans += ((a[i] + c - 1) / c - 1);
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