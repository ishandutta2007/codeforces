#include <iostream>
#include <stdio.h>
using namespace std;

string mp[11];

bool okay() {
    int n=10;
    for (int i=1;n>=i;i++) {
        for (int j=1;n-4>=j;j++) {
            if (mp[i][j] == 'X' && mp[i][j+1]=='X' && mp[i][j+2]=='X' && mp[i][j+3]=='X' && mp[i][j+4]=='X') return true;
        }
    }
    for (int i=1;n-4>=i;i++) {
        for (int j=1;n>=j;j++) {
            if (mp[i][j] == 'X' && mp[i+1][j]=='X' && mp[i+2][j]=='X' && mp[i+3][j]=='X' && mp[i+4][j]=='X') return true;
        }
    }
    for (int i=1;n-4>=i;i++) {
        for (int j=1;n-4>=j;j++) {
            if (mp[i][j] == 'X' && mp[i+1][j+1]=='X' && mp[i+2][j+2]=='X' && mp[i+3][j+3]=='X' && mp[i+4][j+4]=='X') return true;
        }
    }
    for (int i=5;n>=i;i++) {
        for (int j=1;n-4>=j;j++) {
            if (mp[i][j] == 'X' && mp[i-1][j+1]=='X' && mp[i-2][j+2]=='X' && mp[i-3][j+3]=='X' && mp[i-4][j+4]=='X') return true;
        }
    }
    return false;
}

int main () {
    int n=10;
    for (int i=1;10>=i;i++) {
        cin >>mp[i];
        mp[i] = " " + mp[i];
    }
    for (int i=1;n>=i;i++) {
        for (int j=1;n>=j;j++) {
            if (mp[i][j] == '.') {
                mp[i][j] = 'X';
                if (okay()) {
                    puts("YES");
                    return 0;
                }
                mp[i][j] = '.';
            }
        }
    }
    puts("NO");
}