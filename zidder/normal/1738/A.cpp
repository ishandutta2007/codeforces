#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int &i: a) scanf("%d", &i);
    for (int &i: b) scanf("%d", &i);

    vector<int> b1, b0;
    for (int i=0;i<n;++i) {
        if (a[i]) b1.push_back(b[i]);
        else b0.push_back(b[i]);
    }
    sort(b1.begin(), b1.end());
    sort(b0.begin(), b0.end());
    long long ans = 0;
    if (b1.size() == b0.size()) {
        for (int i: b) ans += i;
        ans *= 2;
        ans -= min(b0[0], b1[0]);
    } else {
        if (b1.size() < b0.size()) swap(b1, b0);
        for (int i: b0) ans += i;
        reverse(b1.begin(), b1.end());
        for (int j=0;j<b0.size();++j) ans += b1[j];
        ans *= 2;
        for (int j=b0.size();j<b1.size();++j)  ans += b1[j];
    }
    printf("%lld\n", ans);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}