#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long n;
    cin >> n;
    // any odd > 1
    // any div 4 > 4
    if (n == 1) {
        cout << 3 << endl;
        return;
    }
    long long c = 1;
    long long a = ((n - c) / 3 + 1) * 4ll;
    n -= ((n - c) / 3) * 3 + 1;
    if (n == 0) {
        cout << a << endl;
    } else {
        if (n == 1) {
            cout << a + 1 << endl;
        } else {
            cout << a + 3 << endl;
        }
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}