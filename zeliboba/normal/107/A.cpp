#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n, p;
    cin >> n >> p;
    vi in(n + 1), out(n + 1), dout(n + 1);
    for (int i = 0; i < p; ++i) {
        int a,b,d;
        cin >> a >> b >> d;
        in[b] = a;
        out[a] = b;
        dout[a] = d;
    }
    vvi res;
    for (int i = 1; i <= n; ++i) {
        if (!in[i] && out[i]) {
            int md = dout[i];
            int cur = i;
            while (out[cur]) {
                md = min(md, dout[cur]);
                cur = out[cur];
            }
            res.push_back(vi(3));
            res.back()[0] = i;
            res.back()[1] = cur;
            res.back()[2] = md;
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
    }
    return 0;
}