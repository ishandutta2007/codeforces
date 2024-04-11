#include <iostream>
#include <vector>

using namespace std;

int cnt[10];
int need[10][10][10];

const int INF = 1000;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            for(int m = 0; m <= 9; m++){
               need[i][j][m] = INF;
                for(int k = 0; k <= 10; k++){
                    for(int l = 0; l <= 10; l++){
                        if(k == 0 && l == 0) continue;
                        if((i*k+j*l)%10 == m){
                            need[i][j][m] = min(k+l, need[i][j][m]);
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < s.size()-1; i++){
        int d = s[i+1]-s[i];
        if(d < 0) d += 10;
        cnt[d]++;
    }
    int ans[10][10];
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            ans[x][y] = 0;
            for(int i = 0; i < 10; i++){
                if(cnt[i] != 0){
                    int m = need[x][y][i];
                    if(m == INF){
                        ans[x][y] = -1;
                        break;
                    }else{
                        ans[x][y] += ((m-1)*cnt[i]);
                    }
                }
            }
        }
    }
    for(int x = 0; x < 10; x++){
        for(int y = 0; y< 10; y++){
            if(y != 9){
                cout << ans[x][y] << ' ';
            }else{
                cout << ans[x][y] << endl;
            }
        }
    }
}