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
int n, r1, r2, p, np[50005];
vector <int> v[50005];
void dfs(int i, int parn){
    np[i] = parn;
    for(int j = 0; j < v[i].size(); j++)
        if(v[i][j] != parn)dfs(v[i][j], i);
} 
int main(){
    cin >> n >> r1 >> r2;
    for(int i = 0; i < n; i++)
       if(i != r1 - 1){
           cin >> p;
           v[p - 1].push_back(i);
           v[i].push_back(p - 1);
       }
    dfs(r2 - 1, -1);
    for(int i = 0; i < n; i++)
       if(np[i] != -1)cout << np[i] + 1 << ' ';
    cout << endl;
    return 0;
}