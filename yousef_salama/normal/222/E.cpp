#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#define MOD 1000000007
using namespace std;
int m, k, g[55][55], gt[55][55];
long long n;
string s;
int num(char c){
    if(islower(c))return c - 'a';
    else return c - 'A' + 26;
}
struct Matrix{
    long long a[55][55];
    Matrix(){
        memset(a, 0, sizeof a);
    }
    Matrix operator *(Matrix y){
        Matrix ret = Matrix();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++)
                ret.a[i][j] = (ret.a[i][j] + (a[i][k] * y.a[k][j])) % MOD;
        }
        return ret;
    }
};
int main(){
    cin >> n >> m >> k;
    while(k--){
        cin >> s;
        g[num(s[0])][num(s[1])] = 1;
    }
    for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++)
        gt[i][j] = !g[i][j];
    
    
    Matrix ret = Matrix();
    for(int i = 0; i < m; i++)
        ret.a[i][i] = 1;
    Matrix x = Matrix();
    for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++)
        x.a[i][j] = gt[i][j];
    for(long long i = n - 1; i > 0; i >>= 1){
        if(i & 1)ret = ret * x;
        x = x * x;
    }
    long long ans = 0;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++)
        ans = (ans + ret.a[i][j]) % MOD;
    cout << ans << endl;
}