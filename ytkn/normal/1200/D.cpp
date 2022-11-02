#include <iostream>

using namespace std;

char s[2000][2000];
int col_cnt[2001][2001];
int row_cnt[2001][2001];
int cand[2000][2000];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        row_cnt[i][0] = 0;
        for(int j = 0; j < n; j++){
            if(s[i][j] == 'B') {
                row_cnt[i][j+1] = row_cnt[i][j]+1;
            }else{
                row_cnt[i][j+1] = row_cnt[i][j];
            }
        }
        if(row_cnt[i][n] == 0) ans++;
    }
    for(int j = 0; j < n; j++){
        col_cnt[0][j] = 0;
        for(int i = 0; i < n; i++){
            if(s[i][j] == 'B') {
                col_cnt[i+1][j] = col_cnt[i][j]+1;
            }else{
                col_cnt[i+1][j] = col_cnt[i][j];
            }
        }
        if(col_cnt[n][j] == 0) ans++;
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            cout << row_cnt[i][j] << ' ';
        }
        cout << endl;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < n; j++){
            cout << col_cnt[i][j] << ' ';
        }
        cout << endl;
    }
    */
    for(int i = 0; i+k <= n; i++){
        int cumsum[2001];
        cumsum[0] = 0;
        for(int j = 0; j < n; j++){
            if(col_cnt[n][j] == 0) cumsum[j+1] = cumsum[j];
            else{
                if(col_cnt[i][j] == 0 && (col_cnt[i+k][j] == col_cnt[n][j])){
                    cumsum[j+1] = cumsum[j]+1;
                }else{
                    cumsum[j+1] = cumsum[j];
                }
            }
            //cout << cumsum[j] << ' ';
        }
        //cout << cumsum[n] << endl;
        for(int j = 0; j+k <= n; j++){
            cand[i][j] += cumsum[j+k]-cumsum[j];
        }
    }

    for(int j = 0; j+k <= n; j++){
        int cumsum[2001];
        cumsum[0] = 0;
        for(int i = 0; i < n; i++){
            if(row_cnt[i][n] == 0) cumsum[i+1] = cumsum[i];
            else{
                if(row_cnt[i][j] == 0 && (row_cnt[i][j+k] == row_cnt[i][n])){
                    cumsum[i+1] = cumsum[i]+1;
                }else{
                    cumsum[i+1] = cumsum[i];
                }
            }
            //cout << cumsum[i] << ' ';
        }
        //cout << cumsum[n] << endl;
        for(int i = 0; i+k <= n; i++){
            cand[i][j] += cumsum[i+k]-cumsum[i];
        }
    }
    int tmp = 0;
    for(int i = 0; i+k <= n; i++){
        for(int j = 0; j+k <= n; j++){
            tmp = max(tmp, ans+cand[i][j]);
            //cout << cand[i][j] << ' ';
        }
        //cout << endl;
    }
    //cout << ans << endl;
    cout << tmp << endl;
}