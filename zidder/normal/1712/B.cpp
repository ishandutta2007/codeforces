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
    vector<int> p(n);
    for (int i=n-1;i>=0;--i) {
        if (i == 0) {
            p[i] = i + 1;
            continue;
        }
        p[i] = i;
        p[i-1] = i + 1;
        i--;
    }
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