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
    int k;
    cin >> k;
    int c = 0;
    for (int i=0;i<n;++i) {
        int x;
        cin >> x;
        if (i < k && x > k) c++;
    }
    cout << c << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}