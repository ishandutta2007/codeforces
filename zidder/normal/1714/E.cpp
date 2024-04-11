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
    // 1 -> 2 -> 4 -> 8 -> 6 -> 2
    // 3 -> 6
    // 5 -> 0
    // 7 -> 4
    // 9 -> 8
    int h=0, nh=0;
    for (int i: a) {
        if (i%5) nh++;
        else h++;
    }
    if (h && nh) {
        cout << "No" << endl;
        return;
    }
    for (int &i: a) {
        while (i%10 != 0 && i%10 != 2) {
            i = i + i % 10;
        }
    }
    if (h) {
        for (int i: a) {
            if (i != a[0]) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
        return;
    }
    for (int i: a) if (i%20 != a[0]%20) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}