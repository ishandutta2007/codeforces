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
    vector<int> a(n), b(n);
    for (int &i: a) scanf("%d", &i);
    for (int &i: b) scanf("%d", &i);
    int sa = 0, sb = 0;
    for (int i: a) sa += i;
    for (int i: b) sb += i;
    int ans1 = 0;
    for (int i=0;i<n;++i) ans1 += (a[i] != b[i]);
    cout << min(abs(sa - sb) + 1, ans1) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}