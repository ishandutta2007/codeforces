#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;

int n;

const int maxn = 1e5 + 5;
set<int> s[maxn];
int deg[maxn];
int w[maxn];

pi a[maxn];
long long ans[maxn];
int id[maxn];

bool cmp(int i, int j){
    return w[i] < w[j];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ans[1] = 0;
        for(int i = 1;i <= n;i++){
            cin >> w[i];
            ans[1] += w[i];
            deg[i] = 0;
        }
        for(int i = 1;i < n;i++){
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }
        vector<int> weight;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j < deg[i];j++){
                weight.push_back(w[i]);
            }
        }
        sort(weight.begin(), weight.end());
        for(int i = 2;i < n;i++){
            ans[i] = ans[i - 1] + weight[n - i - 1];
        }
        for(int i = 1;i < n;i++){
            cout << ans[i] << ((i == n - 1) ? '\n' : ' ');
        }
    }
    return 0;
}