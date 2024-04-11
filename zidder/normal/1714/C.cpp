#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int s;
    vector<string> ans(46);
    ans[0] = "";
    auto f = [&](int k){
        return (9 + 9 - k + 1) * k / 2;
    };
    for (s=1;s<=45;++s){
        for (int k=1;k<10;++k) {
            if (f(k) >= s) {
                for (int d=1;d<=9;++d) {
                    if (f(k-1) >= s - d) {
                        ans[s] = to_string(d) + ans[s-d];
                        break;
                    }
                }
                if (ans[s].size()) break;
            }
        }
    }
    cin >> s;
    cout << ans[s] << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}