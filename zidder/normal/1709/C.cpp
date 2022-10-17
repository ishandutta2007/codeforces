#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	string s;
    cin >> s;
    int n = s.size();
    vector<int> qs;
    for (int i=0;i<n;++i) if (s[i] == '?') qs.push_back(i);
    int l = 0, r = 0;
    for (int i=0;i<n;++i) l += s[i] == '(';
    for (int i=0;i<n;++i) r += s[i] == ')';
    int cntr = (((int)qs.size()) - (r - l)) / 2;
    if (cntr == 0 || cntr == qs.size()) {
        cout << "YES" << endl;
        return;
    } 
    vector<int> v(n + 1);
    for (int i=0, qind=0;i<n;++i) {
        if (s[i] == '(') v[i+1] = v[i] + 1;
        if (s[i] == ')') v[i+1] = v[i] - 1;
        if (s[i] == '?') {
            if (qind + cntr + 1 < qs.size()) {
                v[i+1] = v[i] + 1;
            } else if (qind + cntr + 1 == qs.size()){
                v[i+1] = v[i] - 1;
            } else if (qind + cntr == qs.size()) {
                v[i+1] = v[i] + 1;
            } else {
                v[i+1] = v[i] - 1;
            }
            qind++;
        }
        if (v[i+1] < 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}