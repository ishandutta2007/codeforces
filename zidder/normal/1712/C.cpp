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
    for (int &i: a) scanf("%d", &i);
    vector<int> c(n+1);
    for (int i: a) c[i]++;
    int cnt = 0;
    for (int i: c) if (i) cnt++;
    int ans = cnt;
    set<int> bads;
    for (int i=n-1;i>=0;--i) {
        int j = a[i];
        c[j]--;
        if (c[j]) bads.insert(j);
        else {
            bads.erase(j);
            cnt--;
        }
        if (i+1 < n && a[i] > a[i+1]) break;
        if (bads.empty()) {
            ans = cnt;
        }
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