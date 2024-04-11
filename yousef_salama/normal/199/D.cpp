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
int n, k, d[200005][2];
bool v[200005][2];
string s[2];
queue <pair <int, int> > Q;
int main(){
    cin >> n >> k >> s[0] >> s[1];

    Q.push(make_pair(0, 0));
    memset(v, 0, sizeof v);
    memset(d, -1, sizeof d);
    v[0][0] = true;
    d[0][0] = 0;
    while(!Q.empty()){
        pair <int, int> p = Q.front();
        Q.pop();
        if(d[p.first][p.second] > p.first)continue;

        if(p.first > 0 && !v[p.first - 1][p.second] && s[p.second][p.first - 1] != 'X'){
            d[p.first - 1][p.second] = d[p.first][p.second] + 1;
            v[p.first - 1][p.second] = true;
            Q.push(make_pair(p.first - 1, p.second));
        }
        if(p.first + 1 < s[p.second].size() && !v[p.first + 1][p.second] && s[p.second][p.first + 1] != 'X'){
            d[p.first + 1][p.second] = d[p.first][p.second] + 1;
            v[p.first + 1][p.second] = true;
            Q.push(make_pair(p.first + 1, p.second));
        }
        if(p.first + k < s[p.second].size() && !v[p.first + k][p.second ^ 1] && s[p.second ^ 1][p.first + k] != 'X'){
            d[p.first + k][p.second ^ 1] = d[p.first][p.second] + 1;
            v[p.first + k][p.second ^ 1] = true;
            Q.push(make_pair(p.first + k, p.second ^ 1));
        }
    }
    bool found = false;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < 2; j++){
        if(d[i][j] != -1 && d[i][j] <= i)found |= i + k >= n;
    }
    if(found)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}