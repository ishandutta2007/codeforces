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

string s;
ll x, y;
const int maxn = 1e5 + 5;
int pre0[maxn], pre1[maxn];
int suf0[maxn], suf1[maxn];
ll pre[maxn], suf[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    cin >> x >> y;
    if(x < y){
        swap(x, y);
        for(int i = 0;i < s.length();i++){
            if(s[i] == '0')
                s[i] = '1';
            else if(s[i] == '1')
                s[i] = '0';
        }
    }

    int cnt0 = 0, cnt1 = 0; 
    for(int i = 0;i < s.length();i++){
        if(s[i] == '?' or s[i] == '1'){
            cnt1++;
            pre[i + 1] = pre[i] + 1LL * x * pre0[i];
        }
        else{
            cnt0++;
            pre[i + 1] = pre[i] + 1LL * y * pre1[i];
        }
        pre0[i + 1] = cnt0;
        pre1[i + 1] = cnt1;
    }
    cnt0 = 0, cnt1 = 0;
    for(int i = s.length() - 1;i >= 0;i--){
        if(s[i] == '?' or s[i] == '0'){
            cnt0++;
            suf[i + 1] = suf[i + 2] + 1LL * x * suf1[i + 2];
        }else{
            cnt1++;
            suf[i + 1] = suf[i + 2] + 1LL * y * suf0[i + 2];
        }
        suf0[i + 1] = cnt0;
        suf1[i + 1] = cnt1;
    }
    ll ans = pre[0] + suf[1];
    for(int i = 0;i < s.length();i++){
        ans = min(ans, pre[i + 1] + suf[i + 2] + 1LL * pre0[i + 1] * suf1[i + 2] * x + 1LL * pre1[i + 1] * suf0[i + 2] * y);
    } 
    cout << ans << endl;
    return 0;
}