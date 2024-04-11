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
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n;
    string s;
    vector<char> vs;
    cin >> s;
    char cur = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != cur) {
            if (cnt % 2) {
                if (vs.empty() || vs.back() != cur)
                    vs.push_back(cur);
                else vs.pop_back();
            }
            cur = s[i];
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    if (cnt % 2) {
        if (vs.empty() || vs.back() != cur)
            vs.push_back(cur);
        else vs.pop_back();
    }
    for (int i = 0; i < vs.size(); ++i)
        printf("%c", vs[i]);
    printf("\n");
    return 0;
}