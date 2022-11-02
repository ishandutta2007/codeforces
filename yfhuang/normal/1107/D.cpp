#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 5300;
char s[maxn][maxn / 4];
int n;
int bit[maxn][maxn];

int convert(char ch){
    if('0' <= ch && ch <= '9'){
        return ch - '0';
    }else{
        return ch - 'A' + 10;
    }
}
bool check(int m){
    if(m > n) return false;
    if(n % m) return false;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int nx = (i - 1)/ m * m + 1;
            int ny = (j - 1)/ m * m + 1;
            if(bit[i][j] != bit[nx][ny])
                return false;
        }
    }
    return true;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%s", s[i] + 1);
        for(int j = 1;j <= n / 4;j++){
            int num = convert(s[i][j]);
            bit[i][(j - 1) * 4 + 1] = (num & 8) >> 3;
            bit[i][(j - 1) * 4 + 2] = (num & 4) >> 2;
            bit[i][(j - 1) * 4 + 3] = (num & 2) >> 1;
            bit[i][(j - 1) * 4 + 4] = num & 1;
        }
    } 
    /*
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << bit[i][j];
        }
        cout << endl;
    }*/
    int tmp = n;
    vector<int> div;
    for(int i = 2;i <= n;i++){
        if(tmp % i == 0){
            div.push_back(i);
            while(tmp % i == 0){
                tmp /= i;
            }
        }
    }
    vector<int> power;
    for(auto d: div){
        int now = 1;
        int p = 0;
        while(now * d <= n){
            now *= d;
            p++;
        }
        int l = 0, r = p;
        while(l < r){
            int mid = (l + r + 1) / 2;
            int pd = 1;
            for(int i = 1;i <= mid;i++){
                pd *= d;
            }
            if(check(pd)) l = mid;
            else r = mid - 1;
        }
        int pd = 1;
        for(int i = 1;i <= l;i++){
            pd *= d;
        }
        power.push_back(pd);
    }
    long long ans = 1;
    for(auto d: power){
        ans *= d;
    }
    cout << ans << endl;
    return 0;
}