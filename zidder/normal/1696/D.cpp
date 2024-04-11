#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);

    // 3 6 4 2 5 1 7
    
    int ind = 0, c=0;
    int i = 1;
    set<int> nums;
    for (int i: a) nums.insert(i);
    while (ind < n - 1){
        nums.erase(a[ind]);
        bool side = a[ind+1] < a[ind];
        int mind = i;
        for (;i<n;++i) {
            if ((a[i] < a[ind]) ^ side) {
                ind = mind;
                c++;
                break;
            }
            if (a[i] == *nums.begin() && side) {
                ind = i;
                i++;
                c++;
                break;
            }
            if (!side && a[i] == *nums.rbegin()) {
                ind = i;
                i++;
                c++;
                break;
            }
            nums.erase(a[i]);
            if (side) {
                if (a[i] < a[mind]) {
                    mind = i;
                }
            } else {
                if (a[i] > a[mind]) {
                    mind = i;
                }
            }
        }
        // cout << n << " " << ind << " " << i << " " << mind << endl;
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