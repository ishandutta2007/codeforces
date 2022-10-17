#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        cout << '\n';

        int r, c; cin >> r >> c;
        string s[r]; for(auto &i : s) cin >> i;

        bool flag = true;
        for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) if(s[i][j] == 'P') {flag = false; break;}
        if(flag) {cout << 0; continue;}

        flag = true;
        for(int i = 0; i < r; ++i) if(s[i][0] == 'P') {flag = false; break;}
        if(flag) {cout << 1; continue;}

        flag = true;
        for(int i = 0; i < r; ++i) if(s[i][c - 1] == 'P') {flag = false; break;}
        if(flag) {cout << 1; continue;}

        flag = true;
        for(int j = 0; j < c; ++j) if(s[0][j] == 'P') {flag = false; break;}
        if(flag) {cout << 1; continue;}

        flag = true;
        for(int j = 0; j < c; ++j) if(s[r - 1][j] == 'P') {flag = false; break;}
        if(flag) {cout << 1; continue;}

        if(s[0][0] == 'A' || s[0][c - 1] == 'A' || s[r - 1][0] == 'A' || s[r - 1][c - 1] == 'A') {cout << 2; continue;}

        flag = false;
        for(int i = 1; i < r - 1; ++i)
        {
            bool flag1 = true;
            for(int j = 0; j < c; ++j) if(s[i][j] == 'P') {flag1 = false; break;}
            if(flag1) {flag = true; break;}
        }
        if(flag) {cout << 2; continue;}

        flag = false;
        for(int j = 1; j < c - 1; ++j)
        {
            bool flag1 = true;
            for(int i = 0; i < r; ++i) if(s[i][j] == 'P') {flag1 = false; break;}
            if(flag1) {flag = true; break;}
        }
        if(flag) {cout << 2; continue;}

        flag = false;
        for(int i = 1; i < r - 1; ++i) if(s[i][0] == 'A' || s[i][c - 1] == 'A') {flag = true; break;}
        if(flag) {cout << 3; continue;}

        flag = false;
        for(int j = 1; j < c - 1; ++j) if(s[0][j] == 'A' || s[r - 1][j] == 'A') {flag = true; break;}
        if(flag) {cout << 3; continue;}

        flag = false;
        for(int i = 0; i < r; ++i)
        {
            bool flag1 = false;
            for(int j = 0; j < c; ++j) if(s[i][j] == 'A') {flag1 = true; break;}
            if(flag1) {flag = true; break;}
        }
        if(flag) {cout << 4; continue;}

        cout << "MORTAL";
    }
}