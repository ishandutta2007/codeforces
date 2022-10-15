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
    int l = 0, r = n;
    while (l + 1 != r) {
        int m = (l + r) / 2;
        cout << "? " << l + 1 << " " << m << endl;
        fflush(stdout);
        int c = 0;
        for (int i=l;i<m;++i) {
            int x;
            cin >> x;
            x--;
            if (x < m && x >= l) c++;
        }
        if (c%2) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << "! " << l + 1 << endl;
    fflush(stdout);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}