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
    set<int> s;
    for (int i=n-1;i>=0;--i) {
        if (s.count(a[i])) {
            cout << i + 1 << endl;
            return;
        }
        s.insert(a[i]);
    }
    cout << 0 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}