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

const int maxn = 2e5 + 5;

pair<int, pair<int, int>> a[maxn];
int st[maxn];
int tot;
int ans[maxn];
int n;

int solve(int h, int w){
    int l = 0, r = tot;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(a[st[mid]].fi < h){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    if(l == 0){
        return -1;
    }else{
        if(w > a[st[l]].se.fi)
            return a[st[l]].se.se;
        else
            return -1;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            int h, w;
            cin >> h >> w;
            if(h < w) swap(h, w);
            a[i].fi = h;
            a[i].se.fi = w;
            a[i].se.se = i;
        }
        sort(a + 1, a + 1 + n);
        tot = 0;
        for(int i = 1;i <= n;i++){
            int l = 0, r = tot;
            int id = a[i].se.se;
            int ans1 = solve(a[i].fi, a[i].se.fi);
            int ans2 = solve(a[i].se.fi, a[i].fi);
            if(ans1 != -1){
                ans[id] = ans1;
            }else{
                if(ans2 != -1){
                    ans[id] = ans2;
                }else{
                    ans[id] = -1;
                }
            }
            if(tot > 0 and a[i].se.fi < a[st[tot]].se.fi){
                st[++tot] = i;
            }else if(tot == 0){
                st[++tot] = i;
            } 
        }
        for(int i = 1;i <= n;i++){
            cout << ans[i] << ((i == n) ? '\n' : ' ');
        }
    }
    return 0;
}