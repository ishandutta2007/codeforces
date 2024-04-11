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
    string a, b;
    cin >> a >> b;
    if (n < m) {
        cout << "NO" << endl;
        return;
    }
    for (int i=1;i<m;++i){
        if (a[n-m+i] != b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i=0;i<=n-m;++i) {
        if (a[i] == b[0]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}