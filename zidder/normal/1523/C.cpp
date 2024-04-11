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
    for (int i=0;i<n;++i) cin >> a[i];
    vector<vector<int> > res;
    vector<int> stack;
    stack.push_back(0);
    res.push_back(vector<int>(1, 1) );
    if (a[0] != 1) throw "ERROR";
    for (int i=1;i<n;++i){
        if (a[i] == 1){
            res.push_back(res[i-1]);
            res[i].push_back(1);
            stack.push_back(i);
            continue;
        }
        while (!stack.empty()) {
            int ind = stack.back();
            if (a[ind] + 1 == a[i]){
                res.push_back(res[ind]);
                res[i][res[i].size() - 1]++;
                stack[stack.size()-1] = i;
                break;
            }
            stack.pop_back();
        }
        if (stack.empty()) {
            throw "ERROR";
        }
    }
    for (int i=0;i<n;++i){
        cout << res[i][0];
        for (int j=1;j<res[i].size();j++)
            cout << "." << res[i][j];
        cout << endl;
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