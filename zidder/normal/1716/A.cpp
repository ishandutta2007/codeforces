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
    if (n > 4) {
        if (n%3 == 1) {
            cout << 2 + (n - 4) / 3 << endl;
        } else {
            cout << n / 3 + (n%3)/2 << endl;
        }
    } else {
        vector<int> v = {0, 2, 1, 1, 2};
        cout << v[n] << endl;
    }
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}