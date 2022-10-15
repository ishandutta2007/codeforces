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
typedef long long i64;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if ((n % 2) && m >= k) {
        if (!(m % 2)) { 
            if (m >= 2 * k)
                cout << "Timur\n";
            else
                cout << "Marsel\n";
        } else {
            vector<int> div;
            for (int i = 1; i * i <= m; ++i) {
                if (!(m % i)) {
                    if (i >= k)
                        div.push_back(i);
                    if (m / i >= k && i * i != m)
                        div.push_back(m / i);
                }
            }
            sort(div.begin(), div.end());
            vector<bool> res(div.size(), 0);
            for (int i = 0; i < div.size(); ++i) {
//                cerr << div[i] << endl;
                for (int j = 0; j < i; ++j) {
                    if (!res[j] && !(div[i] % div[j])) {
                        res[i] = 1;
                        break;
                    }
                }
            }
            if (res.back())
                cout << "Timur\n";
            else
                cout << "Marsel\n";
        }
    } else {
        cout << "Marsel\n";
    }
    return 0;
}