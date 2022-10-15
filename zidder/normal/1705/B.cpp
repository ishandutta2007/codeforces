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
    vector<long long> a(n);
    for (long long &i: a) scanf("%lld", &i);
    long long ans = 0;
    for (int i=0,j=0;i<n-1;++i) {
        while (j < n-1 && a[j] != 0) j++;
        if (a[i] == 0) {
            if (j == i) j++;
            continue;
        }
        if (j == n-1) {
            ans += a[i];
            continue;
        }
        a[i]--;
        a[j]++;
        i--;
        ans++;
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