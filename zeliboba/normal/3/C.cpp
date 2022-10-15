#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
typedef vector<char> vc;

bool iswin (const vector<vc> & v) {
    bool d1 = true, d2 = true;
    for (int i = 1; i < 3; ++i) {
        if (v[i][i] == '.' || v[i][i] != v[i - 1][i - 1]) 
            d1 = false;
        if (v[i][2 - i] == '.' || v[i][2 - i] != v[i - 1][3 - i]) 
            d2 = false;
    }
    if (d1 || d2)
        return true;
    for (int i = 0; i < 3; ++i) {
        bool d1 = true, d2 = true;
        for (int j = 1; j < 3; ++j) {
            if (v[i][j] == '.' || v[i][j - 1] != v[i][j])
                d1 = false;
            if (v[j][i] == '.' || v[j - 1][i] != v[j][i])
                d2 = false;
        }
        if (d1 || d2)
            return true;
    }
    return false;
}

int main () {
    vector<vc> v(3, vc(3, '.'));
    int cx = 0, c0 = 0;
    for (int i = 0; i < 3; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; ++j) {
            v[i][j] = s[j];
            if (v[i][j] == 'X')
                ++cx;
            if (v[i][j] == '0')
                ++c0;
        }
    }
    if (cx - c0 > 1 || cx < c0) {
        printf("illegal\n");
        return 0;
    }
    if (!iswin(v)) {
        if (cx == 5 && c0 == 4) {
            printf("draw\n");
            return 0;
        }
        if (cx == c0) {
            printf("first\n");
        } else {
            printf("second\n");
        }
        return 0;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            vector<vc> v1 = v;
            v1[i][j] = '.';
            if (!iswin(v1)) {
                if (v[i][j] == 'X') {
                    if (cx - c0 == 1) {
                        printf("the first player won\n");
                    } else {
                        printf("illegal\n");
                    }
                } else {
                    if (cx == c0) {
                        printf("the second player won\n");
                    } else {
                        printf("illegal\n");
                    }
                }
                return 0;
            }
        }
    }
    printf("illegal\n");
    return 0;
}