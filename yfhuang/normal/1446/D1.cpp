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

int n;
int a[maxn];
int pos[maxn * 2];
int cnt[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int mx = 0;
    for(int i = 1;i <= 100;i++){
        mx = max(mx, cnt[i]);
    }
    vector<int> cand;
    for(int i = 1;i <= 100;i++){
        if(mx == cnt[i])
            cand.push_back(i);
    }
    if(cand.size() > 1){
        cout << n << endl;
    }else{
        int v = cand[0];
        int ans = 0;
        for(int i = 1;i <= 100;i++){
            if(i == v)
                continue;
            for(int j = 0;j < maxn * 2;j++){
                pos[j] = 1e9;
            }
            pos[maxn] = 0;
            int now = maxn;
            for(int j = 1;j <= n;j++){
                if(a[j] == i)
                    now--;
                if(a[j] == v)
                    now++;
                ans = max(ans, j - pos[now]);
                pos[now] = min(pos[now], j);
            }
        } 
        cout << ans << endl;
    }
    return 0;
}