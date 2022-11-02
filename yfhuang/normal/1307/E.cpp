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

using namespace std;

int n, m;
const int maxn = 5005;

int s[maxn];
int f[maxn], h[maxn];

int cnt[maxn][maxn];
int pre[maxn][maxn];
//int suf[maxn][maxn];
const int mod = 1e9 + 7;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d", &s[i]);
        pre[i][s[i]]++;
        for(int j = 1;j <= n;j++){
            pre[i][j] += pre[i - 1][j];
        }
    }
    //for(int i = n;i >= 1;i--){
    //    suf[i][s[i]]++;
    //    for(int j = 1;j <= n;j++){
    //        suf[i][j] += suf[i + 1][j];
    //    }
    //}
    for(int i = 1;i <= m;i++){
        scanf("%d%d", &f[i], &h[i]);
        cnt[f[i]][h[i]]++;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    int mx = 0;
    int ans = 0;
    for(int cow = 0;cow <= m;cow++){
        int split;
        if(cow == 0){
            split = 0;
        }else{
            int j;
            int sweet = 0;
            for(j = 1;j <= n;j++){
                if(s[j] == f[cow]){
                    sweet++;
                }
                if(sweet == h[cow]){
                    break;
                }
            }
            if(sweet < h[cow])
                continue;
            else
                split = j;
        }
        int tmp = 0;
        int num = 1;
        if(cow != 0){
            tmp++;
        }
        for(int i = 1;i <= n;i++){
            if(i == f[cow])
                continue;
            int l = pre[split][i], r = pre[n][i] - pre[split][i];
            if(l > r){
                swap(l, r);
            }
            if(cnt[i][l] >= 1 and cnt[i][r] >= 2){
                tmp += 2;
                int x = 1LL * cnt[i][l] * (cnt[i][l] - 1) % mod;
                int y = 1LL * cnt[i][l] * (cnt[i][r] - cnt[i][l]) % mod;
                add(x, y);
                num = 1LL * num * x % mod;
            }else{
                if(cnt[i][l] == 0){
                    if(cnt[i][r] == 0){
                        tmp += 0;
                    }else{
                        tmp += 1;
                        num = 1LL * num * cnt[i][r] % mod;
                    }
                }else if(cnt[i][l] == 1){
                    tmp += 1;
                    num = 2LL * num * cnt[i][l] % mod;
                }
            }
        }
        int r = pre[n][f[cow]] - pre[split][f[cow]];
        if(r >= h[cow]){
            if(cnt[f[cow]][r] >= 2){
                tmp++;
                num = 1LL * num * (cnt[f[cow]][r] - 1) % mod;
            }
        }else{
            if(cnt[f[cow]][r] >= 1){
                tmp++;
                num = 1LL * num * (cnt[f[cow]][r]) % mod;
            }
        }
        //cout << tmp << " " << num << endl;
        if(tmp > mx){
            mx = tmp;
            ans = num;
        }else if(tmp == mx){
            add(ans, num);
        }
    }
    cout << mx << " " << ans << endl;
    return 0;
}