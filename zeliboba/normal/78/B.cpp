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
    int n;
    cin >> n;
    char s[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
    for (int i = 0; i < 3; ++i)
        cout << s[6 - i];
    for (int i = 3; i < n; ++i)
        cout << s[i % 4];
    cout << endl;
    return 0;
}