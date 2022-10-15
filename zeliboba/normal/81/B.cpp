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

bool isdig (char d) {
    return d >= '0' && d <= '9';
}

int main() {
    char s[300];
    gets(s);
    vector<char> res;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') {
            if (i && isdig(s[i - 1])) {
                while (i + 1 < n && s[i + 1] == ' ')
                    ++i;
                if (i + 1 < n && isdig(s[i + 1]))
                    res.push_back(' ');
            }
        } else {
            if (s[i] == ',' && i + 1 < n) {
                res.push_back(',');
                res.push_back(' ');
            } else if (s[i] == '.') {
                i += 2;
                if (!res.empty() && res.back() != ' ') {
                    res.push_back(' ');
                    res.push_back('.');
                    res.push_back('.');
                    res.push_back('.');
                } else {
                    res.push_back('.');
                    res.push_back('.');
                    res.push_back('.');
                }
            } else {
                res.push_back(s[i]);
            }
        }
    }
    while (!res.empty() && res.back() == ' ')
        res.pop_back();
    for (int i = 0; i < res.size(); ++i)
        printf("%c", res[i]);
    printf("\n");
    return 0;
}