#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,k;
    cin >> n >> k;
    int sum=0;
    vector<int> v;
    for (int i=0;i<n;++i) {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }
    sum /= k;
    int tmp=0;
    int pre=0;
    vector<int> ans;
    int last=0;
    for (int i=0;i<n;++i) {
        pre += v[i];
        if (pre == sum) {
            ans.push_back(i-last+1);
            last = i+1;
            pre=0;
        }
    }
    if (pre != 0) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int cnt=0;
        for (int i:ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
}