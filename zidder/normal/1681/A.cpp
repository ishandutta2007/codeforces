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
	int m;
    cin >> m;
    vector<int> b(m);
    for (int &i: b) scanf("%d", &i);
    int mx = 0;
    for (int i: a) mx = max(mx, i);
    for (int i: b) mx = max(mx, i);
    bool ok1=false, ok2=false;
    for (int i: a) if (i == mx) ok1 = true;
    for (int i: b) if (i == mx) ok2 = true;
    if (ok1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    if (ok2) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
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