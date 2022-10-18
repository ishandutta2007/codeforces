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
int main(){
    string a, b;
    cin >> a >> b;
    int n, l = 26, inf = (int)1e9;
    cin >> n;
    int w[l][l];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++)
            w[i][j] = inf;
        w[i][i] = 0;
    }
    while(n--){
        char a, b;
        int cost;
        cin >> a >> b >> cost;
        int n = a - 'a';
        int m = b - 'a';
        w[n][m] = min(w[n][m], cost);
    }
    if(a.size() != b.size()){
        cout << -1 << endl;
        return 0;
    }
    int cost = 0;
    for(int k = 0; k < l; k++)
        for(int i = 0; i < l; i++)
            for(int j = 0; j < l; j++)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
    for(int i = 0; i < a.size(); i++){
        int min = inf;
        char c;
        for(int j = 0; j < l; j++){
            int w1 = w[a[i] - 'a'][j];
            int w2 = w[b[i] - 'a'][j];
            if(w1 + w2 < min){
                min = w1 + w2;
                c = j + 'a';
            }
        }
        if(min == inf){
            cout << -1 << endl;
            return 0;
        }
        cost += min;
        a[i] = c;
    }
    cout << cost << endl;
    cout << a << endl;
    return 0;
}