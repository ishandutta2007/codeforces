//#define NDEBUG
 
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <cassert>
#include <numeric>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mp[10][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,0,0,0},
        {0,1,0,0},
        {2,0,0,0},
        {0,0,1,0},
        {1,1,0,0},
        {0,0,0,1},
        {3,0,0,0},
        {0,2,0,0}
    };
    int d[4] = {};
    for (char c: s) {
        int u = c-'0';
        for (int i = 0; i <= u; i++) {
            for (int j = 0; j < 4; j++) {
                d[j] += mp[i][j];
            }
        }
    }

//    printf("%d %d %d %d\n", d[0], d[1], d[2], d[3]);
    string s2;
    while (d[3]) {
        s2 += '7';
        for (int i = 0; i <= 7; i++) {
            for (int j = 0; j < 4; j++) {
                d[j] -= mp[i][j];
            }
        }
    }
    while (d[2]) {
        s2 += '5';
        for (int i = 0; i <= 5; i++) {
            for (int j = 0; j < 4; j++) {
                d[j] -= mp[i][j];
            }
        }
    }
    while (d[1]) {
        s2 += '3';
        for (int i = 0; i <= 3; i++) {
            for (int j = 0; j < 4; j++) {
                d[j] -= mp[i][j];
            }
        }
    }
    while (d[0]) {
        s2 += '2';
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j < 4; j++) {
                d[j] -= mp[i][j];
            }
        }
    }
    cout << s2 << endl;
    return 0;
}