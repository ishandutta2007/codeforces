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

int n;
const int maxn = 55;
int c[maxn];
int b[maxn];

pair<int, int> search(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(c[j] == c[i] + 1 and j < i){
                return mp(j, i);
            }
        }
    }
    return mp(0, 0);
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
    }
    vector<vector<int>> ans;
    while(1){
        pi p = search();
        if(p == mp(0, 0))
            break;
        vector<int> op;
        int i = p.se;
        while(i > 1 and c[i - 1] == c[i] - 1){
            i--;
        }
        vector<int> b;
        if(p.fi > 1){
            op.push_back(p.fi - 1);
        }
        op.push_back(i - p.fi);
        op.push_back(p.se - i + 1);
        if(p.se < n){
            op.push_back(n - p.se);
        }
        for(int j = p.se + 1;j <= n;j++){
            b.push_back(c[j]);
        }
        for(int j = i;j <= p.se;j++){
            b.push_back(c[j]);
        }
        for(int j = p.fi;j < i;j++){
            b.push_back(c[j]);
        }
        for(int j = 1;j < p.fi;j++){
            b.push_back(c[j]);
        }
        for(int j = 1;j <= n;j++){
            c[j] = b[j - 1];
        }
        ans.push_back(op);
    }
    cout << ans.size() << endl;
    for(auto v : ans){
        cout << v.size();
        for(auto k : v){
            cout << " " << k;
        }
        cout << endl;
    }
    return 0;
}