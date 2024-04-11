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
	string s;
    cin >> s;
    int ind = n;
    for (int i=0;i<n;++i) {
        if (s[i] == '1') {
            ind = i;
            break;
        }
    }
    if (ind == n) {
        cout << "0" << endl;
        return;
    }
    string s1 = s;
    for (int j=ind;j<n;++j) {
        if (s[j] != '0') continue;
        for (int i=0;i<=j;++i){
            string s2 = s;
            for (int k=j;k<n;++k) {
                s2[k] = max(s2[k], s[k-i]);
            }
            s1 = max(s1, s2);
        }
        break;
    }
    s1 = s1.substr(ind, n-ind);
    cout << s1 << endl;
    // n
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}