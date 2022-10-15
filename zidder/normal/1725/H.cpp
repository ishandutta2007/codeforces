#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	// (0, 0) -> 0
    // (1|2, 1|2) -> 2
    // (0, 1|2) -> 1
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    for (int i=0;i<n;++i) a[i]%=3;
    int cz = 0;
    for (int i: a) if (i == 0) cz++;
    if (cz <= n / 2) {
        // z = 0
        // paint zeros 0
        // paint others 1
        cout << 0 << endl;
        int o = n/2-cz;
        string s = "";
        for (int i=0;i<n;++i) {
            if (a[i] == 0) s += '0';
            else {
                if (o) {
                    o--;
                    s += '0';
                } else {
                    s += '1';
                }
            }
        }
        cout << s << endl;
        return;
    }
    // if (cz > n / 2)
    string s = "";
    int o = cz-n/2;
    for (int i=0;i<n;++i){
        if (a[i] != 0) {
            s += '0';
        } else {
            if (o) {
                o--;
                s += '0';
            } else {
                s += '1';
            }
        }
    }
    cout << 2 << endl;
    cout << s << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}