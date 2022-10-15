#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
    long long x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);

    int mn = a[0], mx = a[0];
    int c = 0;
    for (int i=1;i<n;++i) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        if (mx - x > mn + x) {
            mn = mx = a[i];
            c++;
        }
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