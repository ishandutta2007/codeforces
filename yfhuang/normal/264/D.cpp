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

const int maxn = 1e6 + 5;

int l[maxn], r[maxn];

char s[maxn], t[maxn];

int cnt[maxn][3][3];
int n, m;

int id(char c){
    if(c == 'R') return 0;
    if(c == 'G') return 1;
    if(c == 'B') return 2;
    return 3;
}
int main(){
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1); 
    int now = 1;
    for(int i = 1;i <= n;i++){
        while(now <= m and t[now] != s[i]) now++;
        r[i] = min(now, m);
        now++;
    }
    now = 1, l[1] = 1;
    for(int i = 2;i <= n;i++){
        if(now <= m and t[now] == s[i - 1])now++;
        l[i] = now;
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        ans += r[i] - l[i] + 1;
        //cout << r[i] << " " << l[i] << endl;
    }
    memset(cnt, 0, sizeof(cnt));
    for(int i = 2;i <= m;i++){
        memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i]));
        if(t[i] != t[i - 1]){
            cnt[i][id(t[i])][id(t[i - 1])]++;
        }
    }
    for(int i = 2;i <= n;i++){
        ans -= cnt[r[i]][id(s[i - 1])][id(s[i])] - cnt[l[i] - 1][id(s[i - 1])][id(s[i])];
    }
    cout << ans << endl;
    return 0;
}