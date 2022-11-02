#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

int n, m;
const int maxn = 1e6 + 5;

vector<int> G[maxn];
set<int> s1, s2;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    for(int i = 1;i <= n;i++){
        s1.insert(i);
    }
    while(!s1.empty()){
        auto it = s1.begin();
        int x = *it;
        for(auto v : G[x]){
            if(s1.find(v) != s1.end()){
                s1.erase(v);
            }
        }
        s2.insert(-x);
        s1.erase(it);
    }
    while(!s2.empty()){
        auto it = s2.begin();
        int x = *it;
        x = -x;
        for(auto v : G[x]){
            if(s2.find(-v) != s2.end()){
                s2.erase(-v);
            }
        } 
        s1.insert(x);
        s2.erase(it);
    }  
    cout << s1.size() << endl;
    for(auto v : s1){
        cout << v << " ";
    }
    return 0;
}