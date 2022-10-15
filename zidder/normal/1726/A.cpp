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
    int ans = a[n-1] - a[0];
    for (int i=1;i<n;++i) ans = max(ans, a[i-1] - a[i]);
    for (int i=0;i<n-1;++i) ans = max(ans, a[n-1] - a[i]);
    for (int i=1;i<n;++i) ans = max(ans, a[i] - a[0]);
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