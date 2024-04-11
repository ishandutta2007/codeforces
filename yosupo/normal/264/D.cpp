#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
const int MAX_N = 1000010;

int strdata1[MAX_N], strdata2[MAX_N];
int n1, n2;
int data[MAX_N][3][3];

int main(int argc, char *argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    n1 = s1.size(); n2 = s2.size();
    for (int i = 0; i < n1; i++) {
        switch (s1[i]) {
            case 'R':
                strdata1[i] = 0;
                break;
            case 'G':
                strdata1[i] = 1;
                break;
            case 'B':
                strdata1[i] = 2;
                break;
        }
    }
    for (int i = 0; i < n2; i++) {
        switch (s2[i]) {
            case 'R':
                strdata2[i] = 0;
                break;
            case 'G':
                strdata2[i] = 1;
                break;
            case 'B':
                strdata2[i] = 2;
                break;
        }
    }

    int num[3][3] = {};
    int c1 = strdata2[0];
    for (int i = 1; i < n2; i++) {
        int c2 = strdata2[i];
        num[c1][c2]++;
        c1 = c2;
        copy((int *)num, (int *)num + 9, (int *)data[i]);
    }

    ll result = 0;
    int dp_min = 0, dp_max = 0;
    for (int i = 0; i < n1; i++) {
        int c1 = strdata1[i];
        for (; dp_max < n2; dp_max++) {
            if (strdata2[dp_max] == c1) break;
        }
        dp_max = min(n2-1, dp_max);
        result += dp_max - dp_min + 1;
        if (dp_max - dp_min && i && c1 != strdata1[i-1]) {
            result -= data[dp_max][c1][strdata1[i-1]];
            result += data[dp_min][c1][strdata1[i-1]];
        }
        if (strdata2[dp_max] == c1) dp_max++;
        if (strdata2[dp_min] == c1) dp_min++;
        if (dp_min >= n2) break;
    }
    cout << result << endl;
    return 0;
}