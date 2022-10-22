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
    vector<bool> b(10, true);
    for (int i=0;i<n;++i) {
        int x;
        cin >> x;
        b[x] = false;
    }
    int ans = 0, c=0;
    for (int i=0;i<10;++i) {
        c+=b[i];
    }
    ans = c * (c - 1) * 3;
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