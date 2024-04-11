#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> L(m), id(m);
    for (int i = 0; i < m; i++) {
        string str(m, '0');
        str[i] = '1';
        cout << "? " << str << endl;
        cin >> L[i];
    }
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) { return L[i] < L[j]; });
    int cur = 0;
    string str(m, '0');
    for (int i : id) {
        str[i] = '1';
        cout << "? " << str << endl;
        int v;
        cin >> v;
        if (v == cur + L[i]) cur = v;
        else str[i] = '0';
    }
    cout << "! " << cur << endl;
    return 0;
}