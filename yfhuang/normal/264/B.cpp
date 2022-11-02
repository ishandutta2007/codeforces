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

const int maxn = 1e5 + 5;
bool vis[maxn];
vector<int> p[maxn];
void init(){
    vis[1] = true;
    for(int i = 2;i < maxn;i++){
        if(!vis[i]){
            p[i].push_back(i);
            for(int j = i * 2;j < maxn;j += i){
                vis[j] = true;
                p[j].push_back(i);
            }
        }
    }
}

int n;
int a[maxn];

int dp[maxn];
int dp1[maxn];
int main(){
    init();
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        for(auto v : p[a[i]]){
            dp[i] = max(dp[i], dp1[v] + 1);
        }
        for(auto v : p[a[i]]){
            dp1[v] = max(dp[i], dp1[v]);
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}