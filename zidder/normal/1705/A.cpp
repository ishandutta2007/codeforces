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
    int x;
    cin >> x;
    vector<int> h(2*n);
    for (int &i: h) scanf("%d", &i);
    sort(h.begin(), h.end());
    for (int i=0;i<n;++i) {
        if (h[i] + x > h[i+n]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}