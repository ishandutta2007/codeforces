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

int n, k;
const int maxn = 5e5 + 5;
ll c[maxn];
int Count[maxn];

ll solve(int m, int l){
    int r = n - m; 
    memset(Count, 0, sizeof(Count));
    for(int i = 0;i < r;i++){
        Count[i / k]++; 
    } 
    for(int i = 0;i < m - l;i++){
        Count[i]++;
    }
    int now = 0;
    int now1 = m - l;
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        if(c[i] < 0){
            if(Count[now] == 0){
                now++;
            }
            ans += now * c[i];
            Count[now]--;
        }else{
            ans += c[i] * (now1++);
        } 
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
        if(c[i] >= 0){
            cnt++;
        }
    }
    sort(c + 1, c + 1 + n);
    if(k == 0){
        cout << solve(n, cnt) << endl;
        return 0;
    }
    int l = cnt, r = n;
    while(l < r - 10){
        int ml = (l + l + r) / 3;
        int mr = (l + r + r) / 3;
        if(solve(ml, cnt) >= solve(mr, cnt)){
            r = mr;
        }else{
            l = ml;
        }
    } 
    ll ans = -1e18;
    for(int i = l;i <= r;i++){
        ans = max(ans, solve(i, cnt));
    }
    cout << ans << endl;
    return 0;
}