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
    int d = 2;
    vector<int> p;
    set<int> s;
    for (int i=1;i<=n;++i) s.insert(i);
    while (!s.empty()) {
        int num = *s.begin();
        while (num <= n) {
            s.erase(num);
            p.push_back(num);
            num *= d;
        }
    }
    cout << d << endl;
    for (int i: p) printf("%d ", i);
    cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}