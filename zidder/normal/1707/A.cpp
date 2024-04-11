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
    int q;
    cin >> q;
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    // q - a[i]
    string s = "";
    int mn = 0;
    for (int i=n-1;i>=0;--i) {
        if (mn == q) {
            s += "01"[a[i] <= q];
            continue;
        }
        s += "1";
        if (a[i] > mn) {
            mn++;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}