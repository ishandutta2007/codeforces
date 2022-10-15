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
    auto check = [&]() -> bool {
        bool inc = true;
        for (int i=1;i<n;++i){
            if (a[i] < a[i-1]) {
                if (inc) inc = false;
                else continue;
            }
            if (a[i] > a[i-1]) {
                if (inc) continue;
                else return false;
            }
        }
        return true;
    };
    bool b = check();
    // 2 1 1 2
    if (b) printf("YES\n");
    else printf("NO\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}