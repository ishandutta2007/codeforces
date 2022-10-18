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
int n, m, U[5005], D[5005], L[5005], R[5005];
string s;
char g[5005];
int x(int i, int j){
    return i * m + j;
}
void Delete(int i){
    if(U[i] != -1)D[U[i]] = D[i];
    if(D[i] != -1)U[D[i]] = U[i];
    if(R[i] != -1)L[R[i]] = L[i];
    if(L[i] != -1)R[L[i]] = R[i];
}
void Insert(int i){
    if(U[i] != -1)D[U[i]] = i;
    if(D[i] != -1)U[D[i]] = i;
    if(R[i] != -1)L[R[i]] = i;
    if(L[i] != -1)R[L[i]] = i;
}
int calc(int i){
    int ans = 1;
    if(g[i] == 'U'){
        if(U[i] != -1){
            Delete(i);
            ans = 1 + calc(U[i]);
            Insert(i);
        }
    }else if(g[i] == 'D'){
        if(D[i] != -1){
            Delete(i);
            ans = 1 + calc(D[i]);
            Insert(i);
        }
    }else if(g[i] == 'R'){
        if(R[i] != -1){
            Delete(i);
            ans = 1 + calc(R[i]);
            Insert(i);
        }
    }else{
        if(L[i] != -1){
            Delete(i);
            ans = 1 + calc(L[i]);
            Insert(i);
        }
    }
    return ans;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++)
            g[x(i, j)] = s[j];
    }
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        //Up
        if(i == 0)U[x(i, j)] = -1;
        else{
            if(g[x(i - 1, j)] != '.')U[x(i, j)] = x(i - 1, j);
            else U[x(i, j)] = U[x(i - 1, j)];
        }
        //Left    
        if(j == 0)L[x(i, j)] = -1;
        else{
            if(g[x(i, j - 1)] != '.')L[x(i, j)] = x(i, j - 1);
            else L[x(i, j)] = L[x(i, j - 1)];
        }
    }
    for(int i = n - 1; i >= 0; i--)
    for(int j = m - 1; j >= 0; j--){
        //Down
        if(i == n - 1)D[x(i, j)] = -1;
        else{
            if(g[x(i + 1, j)] != '.')D[x(i, j)] = x(i + 1, j);
            else D[x(i, j)] = D[x(i + 1, j)];
        }
        //Right
        if(j == m - 1)R[x(i, j)] = -1;
        else{
            if(g[x(i, j + 1)] != '.')R[x(i, j)] = x(i, j + 1);
            else R[x(i, j)] = R[x(i, j + 1)];
        }

    }
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(g[x(i, j)] != '.'){
            int ret = calc(x(i, j));

            if(ret > ans)ans = ret, cnt = 1;
            else if(ret == ans)cnt++;
        }
    cout << ans << ' ' << cnt << endl;
    return 0;
}