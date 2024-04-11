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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;
int X0, Y0, X1, Y1, n, r[100005], a[100005], b[100005], d[100005], cnt;
map < pair <int, int>, int> mp;
vector < pair <int, int> > v;
int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main(){
    scanf("%d %d %d %d %d", &X0, &Y0, &X1, &Y1, &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &r[i], &a[i], &b[i]);
        for(int y = a[i]; y <= b[i]; y++){
            mp[make_pair(r[i], y)] = cnt++;
            v.push_back(make_pair(r[i], y));
        }
    }
    queue <int> q;
    memset(d, -1, sizeof d);
    
    q.push(mp[make_pair(X0, Y0)]);
    d[mp[make_pair(X0, Y0)]] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 8; dir++){
            int ni = v[cur].first + di[dir], nj = v[cur].second + dj[dir];
            if(mp.count(make_pair(ni, nj))){
                int ind = mp[make_pair(ni, nj)];
                if(d[ind] == -1){
                    d[ind] = d[cur] + 1;
                    q.push(ind);
                }
            }
        }
    }
    printf("%d\n", d[mp[make_pair(X1, Y1)]]);
    return 0;
}