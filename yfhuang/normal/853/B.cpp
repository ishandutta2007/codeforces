#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

const int maxn = 1e6 + 5;

vector<pair<int,int> > dep[maxn];
vector<pair<int,int> > arr[maxn];

int n,m,k;

int cost[maxn];

long long pre[maxn],suf[maxn];


int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int d,f,t,c;
        scanf("%d%d%d%d",&d,&f,&t,&c);
        if(f == 0){
            dep[d].push_back(make_pair(t,c));
        }else{
            arr[d].push_back(make_pair(f,c));
        }
    }
    for(int i = 1;i <= 1e6;i++){
        cost[i] = 1e9;
        pre[i] = 1e18;
        suf[i] = 1e18;
    }
    int num = 0;
    long long sum = (long long)(1e9) * n;
    for(int i = 1;i <= 1e6;i++){
        for(auto x : arr[i]){
            int u = x.first;
            int c = x.second;
            if(cost[u] == 1e9){
                num++;
            }
            sum -= cost[u];
            cost[u] = min(cost[u],c);
            sum += cost[u];
        }
        if(num == n){
            pre[i] = min(pre[i],sum);
        }
    }
    for(int i = 1;i <= 1e6;i++){
        cost[i] = 1e9;
    }
    num = 0;sum = (long long) (1e9) * n;
    for(int i = 1e6;i >= 1;i--){
        for(auto x : dep[i]){
            int u = x.first;
            int c = x.second;
            if(cost[u] == 1e9){
                num++;
            }
            sum -= cost[u];
            cost[u] = min(cost[u],c);
            sum += cost[u];
        }
        if(num == n){
            suf[i] = min(suf[i],sum);
        }
    }
    long long ans = 2e18;
    for(int i = 1;i <= 1e6;i++){
        if(i + k + 1 <= 1e6){
            if(pre[i] != 1e18 && suf[i + k + 1] != 1e18){
                ans = min(ans,pre[i] + suf[i + k + 1]);
            }
        }
    }
    if(ans == 2e18){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}