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
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    if (k == 1) {
        cout << (n-1) / 2 << endl;
    } else {
        int c = 0;
        for (int i=1;i<n-1;++i) if (a[i] > a[i-1] + a[i+1]) c++;
        cout << c << endl;
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