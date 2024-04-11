#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

set<int> s[maxn];
int n, m;

set<int> now;

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        s[a].insert(b);
        s[b].insert(a);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        now.insert(i);
    }
    for(int i = 1;i <= n;i++){
        if(!now.count(i)) continue;
        ans++;
        queue<int> q;
        q.push(i);
        now.erase(i);
        while(!q.empty()){
            int p = q.front();q.pop();
            vector<int> v;
            for(auto it : now){
                if(!s[p].count(it)){
                    v.push_back(it); 
                }
            }
            for(auto it : v){
                q.push(it);
                now.erase(it);
            }
        }
    }
    cout << ans - 1<< endl;
    return 0;
}