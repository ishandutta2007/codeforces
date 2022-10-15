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
    int l = 0;
    int r = n;
    while (l < n && a[l] == 0) l++;
    // a[l] != 0
    while (r && a[r-1] == 0) r--;
    // a[r] != 0
    if (l >= r) {
        cout << 0 << endl;
    } else {
        for (int i=l;i<r;++i) {
            if (a[i] == 0) {
                cout << 2 << endl;
                return;
            }
        }
        cout << 1 << endl;
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