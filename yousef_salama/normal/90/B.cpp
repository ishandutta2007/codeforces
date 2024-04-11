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
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    string g[n], d[n];
    for(int i = 0; i < n; i++){
        cin >> g[i];
        d[i] = g[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool wrong = 0;
            for(int k = 0; k < m; k++){
                if(g[i][j] == g[i][k] && j != k){
                    g[i][k] = '.';
                    wrong = 1;
               }
            }
            if(wrong)g[i][j] = '.';
        }
    }
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            bool wrong = 0;
            for(int k = 0; k < n; k++){
                if(d[j][i] == d[k][i] && j != k){
                    d[k][i] = '.';
                    wrong = 1;
               }
            }
            if(wrong)d[j][i] = '.';
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(g[i][j] != '.' && d[i][j] != '.')cout << g[i][j];
        }
    return 0;
}