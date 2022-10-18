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
int n, m, k, a, b;
bool v[100005];
vector <int> g[100005], C;
int dfs(int i){
    v[i] = true;

    int ans = 1;
    for(int j = 0; j < g[i].size(); j++)
        if(!v[g[i][j]])ans += dfs(g[i][j]);
    return ans;
}
int main(){
    cin >> n >> m >> k;
    while(m--){
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    memset(v, 0, sizeof v);
    for(int i = 0; i < n; i++)
        if(!v[i])C.push_back(dfs(i));

    if(C.size() == 1)cout << (1 % k) << endl;
    else{
        long long ans = 1;
        for(int i = 0; i < C.size(); i++)
            ans = (ans * C[i]) % k;
        for(int i = 0; i < C.size() - 2; i++)
            ans = (ans * n) % k;
        cout << (ans % k) << endl;
    }
    return 0;
}