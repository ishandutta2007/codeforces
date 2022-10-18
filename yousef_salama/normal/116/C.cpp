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
#include <string.h>
using namespace std;
int n, a;
vector <int> g[2005];
int Bfs(int i){
    int ans = 0;
    queue <pair <int, int> > q;
    q.push(make_pair(i, 0));
    while(!q.empty()){
        pair <int, int> p = q.front();
        q.pop();
        ans = p.second;
        for(int i = 0; i < g[p.first].size(); i++)
            q.push(make_pair(g[p.first][i], p.second + 1));
    }
    return ans;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a != -1)g[a - 1].push_back(i);
    }
    int maxN = 0;
    for(int i = 0; i < n; i++)
        maxN = max(maxN, Bfs(i));
    cout << maxN + 1 << endl;
//    queue <pair<int, int> > q;
//    q.push(make_pair(0, 0));
//    int maxN = 0;
//    while(!q.empty()){
//        pair <int, int> p = q.front();
//        q.pop();
//        maxN = p.first;
//        for(int i = 0; i < n; i++)if(g[p.first][i])
//            q.push(make_pair(i, p.second + 1));
//    }
//    q.push(make_pair(maxN, 0));
//    int ans = 0;
//    while(!q.empty()){
//        pair <int, int> p = q.front();
//        q.pop();
//        ans = p.second;
//        for(int i = 0; i < n; i++)if(g[i][p.first])
//            q.push(make_pair(i, p.second + 1));
//    }
//    cout << ans + 1 << endl;
    return 0;
}