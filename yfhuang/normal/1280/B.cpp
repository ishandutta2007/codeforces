#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int r, c;

const int maxn = 65;

char s[maxn][maxn];

bool row[maxn], col[maxn];
int t;
int main(){
    cin >> t;
    while(t--){
        cin >> r >> c;
        for(int i = 1;i <= r;i++){
            scanf("%s", s[i] + 1);
        }
        bool flag1 = true;
        for(int i = 1;i <= r;i++){
            for(int j = 1;j <= c;j++){
                if(s[i][j] == 'A')
                    flag1 = false;
            }
        }
        if(flag1){
            puts("MORTAL");
            continue;
        }
        bool flag2 = true;
        for(int i = 1;i <= r;i++){
            for(int j = 1;j <= c;j++){
                if(s[i][j] == 'P')
                    flag2 = false;
            }
        }
        if(flag2){
            puts("0");
            continue;
        }
        for(int i = 1;i <= r;i++){
            row[i] = true;
            for(int j = 1;j <= c;j++){
                if(s[i][j] == 'P')
                    row[i] = false;
            }
        }
        for(int i = 1;i <= c;i++){
            col[i] = true;
            for(int j = 1;j <= r;j++){
                if(s[j][i] == 'P')
                    col[i] = false;
            }
        }
        if(col[1] or col[c] or row[1] or row[r]){
            puts("1");
            continue;
        }
        bool flag4 = false;
        for(int i = 1;i <= c;i++){
            if(col[i])
                flag4 = true;
        }
        for(int i = 1;i <= r;i++){
            if(row[i])
                flag4 = true;
        }
        if(flag4){
            puts("2");
            continue;
        }
        if(s[1][1] == 'A' or s[r][1] == 'A' or s[1][c] == 'A' or s[r][c] == 'A'){
            puts("2");
            continue;
        }
        bool flag3 = false;
        for(int i = 1;i <= c;i++){
            if(s[1][i] == 'A' or s[r][i] == 'A')
                flag3 = true;
        }
        for(int i = 1;i <= r;i++){
            if(s[i][1] == 'A' or s[i][c] == 'A')
                flag3 = true;
        }
        if(flag3){
            puts("3");
            continue;
        }
        puts("4");
    }
    return 0;
}