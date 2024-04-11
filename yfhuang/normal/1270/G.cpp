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

int t;

int n;
const int maxn = 1e6 + 5;

int a[maxn];
bool vis[maxn];

int main(){
    cin >> t;
    while(t--){
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1;i <= n;i++){
            vis[i] = false;
        }
        int x = 1;
        while(!vis[x]){
            vis[x] = true;
            x = x - a[x];
        }
        int cur = x;
        vector<int> ans;
        do{
            ans.push_back(cur); 
            cur = cur - a[cur];
        }while(cur != x);
        printf("%d\n", ans.size());
        for(int i = 0;i < ans.size();i++){
            printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}