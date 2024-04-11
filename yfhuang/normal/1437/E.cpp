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
int a[maxn];
int b[maxn];
int c[maxn];
int len[maxn];
bool fix[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        c[i] = a[i] - i;
        len[i] = 1e9;
    }
    for(int i = 1;i <= k;i++){
        cin >> b[i];
        fix[b[i]] = 1;
    }
    c[n + 1] = 1e9;
    fix[n + 1] = 1;
    int pre = -1e9;
    bool flag = true;
    int ans = 0;
    int cnt = 0;
    len[0] = -1e9;
    for(int i = 1;i <= n + 1;i++){
        if(c[i] < pre){
            if(fix[i]){
                flag = false;
                break;
            }else{
                continue;
            }
        }
        int j = upper_bound(len, len + cnt + 1, c[i]) - len;
        cnt = max(cnt, j);
        len[j] = min(len[j], c[i]);
        if(fix[i]){
            ans += j;
            pre = c[i];
            for(int l = 1;l <= cnt;l++){
                len[l] = 1e9;
            }
            cnt = 0;
        }
    }
    if(flag)
        cout << n + 1 - ans << endl;
    else{
        cout << -1 << endl;
    }
    return 0;
}