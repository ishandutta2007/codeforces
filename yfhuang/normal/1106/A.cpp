#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int dx[5] = {-1, -1, 0, 1, 1};
int dy[5] = {-1, 1, 0, -1, 1};

int n;
const int maxn = 505;
char s[maxn][maxn];

bool in(int x,int y){
    return x > 0 && x <= n && y > 0 && y <= n;
}


int main(){
    while(cin >> n){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            scanf("%s", s[i] + 1);
        }
        for(int i = 2;i <= n - 1;i++){
            for(int j = 2;j <= n - 1;j++){
                bool flag = true;
                for(int k = 0;k < 5;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(s[nx][ny] != 'X')
                        flag = false;
                }
                if(flag) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}