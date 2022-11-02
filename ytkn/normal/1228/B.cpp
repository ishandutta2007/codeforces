#include <iostream>

using namespace std;
const long MOD = 1000000007;

int f[1000][1000];

void init(){
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            f[i][j] = -1;
        }
    }    
}

int main(){
    int h, w;
    cin >> h >> w;
    init();
    for(int i = 0; i < h; i++){
        int r;
        cin >> r;
        if(r == 0) f[i][0] = 0;
        for(int j = 0; j < r; j++) f[i][j] = 1;
        f[i][r] = 0;
    }
    for(int i = 0; i < w; i++){
        int c;
        cin >> c;
        if(c == 0){
            if(f[0][i] == 1){
                cout << 0 << endl;
                return 0;
            }
            f[0][i] = 0;
        }
        for(int j = 0; j < c; j++){
            if(f[j][i] == 0){
                cout << 0 << endl;
                return 0;
            }
            f[j][i] = 1;
        }
        if(f[c][i] == 1){
            cout << 0 << endl;
            return 0;
        }
        f[c][i] = 0;
    }
    long ans = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(f[i][j] == -1){
                ans *= 2;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
}