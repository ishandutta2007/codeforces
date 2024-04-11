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

int n, m;

const int maxn = 2005;
pi rob[maxn], pol[maxn];
int st[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> rob[i].fi >> rob[i].se;
    }
    for(int i = 1;i <= m;i++){
        cin >> pol[i].fi >> pol[i].se;
    }
    vector<int> c(1e6 + 5, 0);
    vector<vector<int>> event(1e6 + 5, vector<int>(0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(pol[j].fi >= rob[i].fi){
                int delta = pol[j].fi - rob[i].fi;
                int h = max(0, pol[j].se + 1 - rob[i].se);
                event[delta].push_back(h);
            }
        }
    }
    int ans = 1e9;
    int mx = 0;
    for(int i = 1000000;i >= 0;i--){
        for(auto v : event[i]){
            mx = max(mx, v);
        }
        ans = min(ans, i + mx);
    }
    cout << ans << endl;
    return 0;
}