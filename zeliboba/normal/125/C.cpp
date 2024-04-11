#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main () {
    int n;
    cin >> n;
    vector<vector<int> > res;
    int cur = 1;
    for (int k = 0; k * (k + 1) <= 2 * n; ++k) {
        res.push_back(vector<int>());
        for (int i = 0; i < k; ++i) {
            res[i].push_back(cur);
            res[k].push_back(cur);
            ++cur;
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}