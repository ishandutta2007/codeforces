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
    set<int> cur;
    int c = 0, x = 0;
    for (int i=0;i<n;++i) {
        cur.insert(x);
        x ^= a[i];
        if (cur.find(x) != cur.end()) {
            cur.clear();
            x = 0;
        } else {
            c++;
        }
        // a[i+1] or cur[i] ^ a[i+1]
    }
    printf("%d\n", c);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}