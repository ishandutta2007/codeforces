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
using namespace std;
int N, M, K, temp;
string g[1005];
int ins[100005][2], U[1005][1005], L[1005][1005], R[1005][1005], D[1005][1005];
map <char, int> mp;
char c;
bool check(int i, int j){
    for(int k = 0; k < K; k++){
        if(ins[k][0] == 0){
            if(i - ins[k][1] < 0 || U[i][j] - 1 < ins[k][1])
                return false;
            i -= ins[k][1];
        }else if(ins[k][0] == 1){
            if(i + ins[k][1] >= N || D[i][j] - 1 < ins[k][1])
                return false;
            i += ins[k][1];
        }else if(ins[k][0] == 2){
            if(j + ins[k][1] >= M || R[i][j] - 1 < ins[k][1])
                return false;
            j += ins[k][1];
        }else{
            if(j - ins[k][1] < 0 || L[i][j] - 1 < ins[k][1])
                return false;
            j -= ins[k][1];
        }
    }
    return true;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> g[i];
    cin >> K;
    mp['N'] = 0;
    mp['S'] = 1;
    mp['E'] = 2;
    mp['W'] = 3;
    for(int i = 0; i < K; i++){
        cin >> c >> temp;
        ins[i][0] = mp[c];
        ins[i][1] = temp;
    }
    for(int i = 0; i < N; i++)
        L[i][0] = (g[i][0] != '#');
    for(int i = 0; i < N; i++)
        for(int j = 1; j < M; j++){
            if(g[i][j] == '#')L[i][j] = 0;
            else L[i][j] = L[i][j - 1] + 1;
        }
    for(int i = 0; i < N; i++)
        R[i][M - 1] = (g[i][M - 1] != '#');
    for(int i = 0; i < N; i++)
        for(int j = M - 2; j >= 0; j--){
            if(g[i][j] == '#')R[i][j] = 0;
            else R[i][j] = R[i][j + 1] + 1;
        }
    for(int j = 0; j < M; j++)
        U[0][j] = (g[0][j] != '#');
    for(int i = 1; i < N; i++)
        for(int j = 0; j < M; j++){
            if(g[i][j] == '#')U[i][j] = 0;
            else U[i][j] = U[i - 1][j] + 1;
        }
    for(int j = 0; j < M; j++)
        D[N - 1][j] = (g[N - 1][j] != '#');
    for(int i = N - 2; i >= 0; i--)
        for(int j = 0; j < M; j++){
            if(g[i][j] == '#')D[i][j] = 0;
            else D[i][j] = D[i + 1][j] + 1;
        }
    string ans = "";
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)if(isalpha(g[i][j]))
            if(check(i, j))
                ans += g[i][j];
    sort(ans.begin(), ans.end());
    if(ans.empty())cout << "no solution" << endl;
    else cout << ans << endl;
    return 0;
}