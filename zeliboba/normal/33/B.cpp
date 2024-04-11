#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

const int MAX = 1000000000;

int main() {
    string s,t;
    cin >> s >> t;
    if (s.size() != t.size()) {
        cout << -1;
        return 0;
    }
    int n;
    cin >> n;
    vector<char> a(n), b(n);
    vector<vi> gr(26, vi(26, MAX));
    vi w(n);
    for (int i = 0; i < n; ++i) {
        string buf1, buf2;
        cin >> buf1 >> buf2 >> w[i];
        a[i] = buf1[0];
        b[i] = buf2[0];
        gr[a[i] - 'a'][b[i] - 'a'] = min(gr[a[i] - 'a'][b[i] - 'a'], w[i]);
    }
    for (int i = 0; i < gr.size(); ++i)
        gr[i][i] = 0;
    for (int k = 0; k < gr.size(); ++k) 
        for (int i = 0; i < gr.size(); ++i)
            for (int j = 0; j < gr.size(); ++j)
                gr[i][j] = min (gr[i][j], gr[i][k] + gr[k][j]);
    long long sum = 0;
    string res(s.size(), 'a');
    for (int i = 0; i < t.size(); ++i) {
        int cur = MAX;
        for (int j = 0; j < gr.size(); ++j) {
            if (cur > gr[s[i] - 'a'][j] + gr[t[i] - 'a'][j]) {
                cur = gr[s[i] - 'a'][j] + gr[t[i] - 'a'][j];
                res[i] = 'a' + j;
            }
        }
        if (cur == MAX) {
            cout << -1;
            return 0;
        } else
            sum += cur;
    }
    cout << sum << endl << res << endl;
    return 0;
}