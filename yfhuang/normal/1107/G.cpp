#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 3e5 + 5;
int n, a;
int d[maxn], c[maxn];
long long pre[maxn], suf[maxn];
long long p[20][maxn], s[20][maxn];
void rmq_init(){
    for(int i = 0;i <= n + 1;i++){
        p[0][i] = pre[i];
        s[0][i] = suf[i];
    }
    for(int j = 1;(1 << j) <= n + 2;j++){
        for(int i = 0;i + (1 << j) - 1 <= n + 1;i++){
            p[j][i] = min(p[j - 1][i], p[j - 1][i + (1 << (j - 1))]);
            s[j][i] = min(s[j - 1][i], s[j - 1][i + (1 << (j - 1))]);
        }
    }
}

long long query(int l, int r, int type){
    int k = 31 - __builtin_clz(r - l + 1);
    if(type == 0){
        return min(p[k][l], p[k][r - (1 << k) + 1]);
    }else{
        return min(s[k][l], s[k][r - (1 << k) + 1]);
    }
}

int q[maxn], tot;
int L[maxn], R[maxn];
int main(){
    while(cin >> n >> a){
        pre[0] = 0;
        suf[n + 1] = 0;
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d%d", &d[i], &c[i]);
            c[i] = a - c[i];
            pre[i] = pre[i - 1] + c[i];
            ans = max(ans, (long long)c[i]);
        }
        for(int i = n;i >= 1;i--){
            suf[i] = suf[i + 1] + c[i];
        }
        pre[n + 1] = pre[n];
        suf[0] = suf[1];
        tot = 0;
        for(int i = 1;i < n;i++){
            int now = d[i + 1] - d[i];
            while(tot > 0 && ((d[q[tot] + 1] - d[q[tot]]) <= now)){
                tot--;
            }
            if(tot == 0){
                L[i] = 1;
            }else{
                L[i] = q[tot] + 1;
            }
            q[++tot] = i;
        }
        tot = 0;
        for(int i = n - 1;i >= 1;i--){
            int now = d[i + 1] - d[i];
            while(tot > 0 && ((d[q[tot] + 1] - d[q[tot]]) <= now)){
                tot--;
            }
            if(tot == 0){
                R[i] = n;
            }else{
                R[i] = q[tot];
            }
            q[++tot] = i;
        }
        rmq_init();
        for(int i = 1;i < n;i++){
            int l, r;
            l = L[i] - 1;
            r = i - 1;
            long long tmp1 = query(l, r, 0);
            l = i + 2;
            r = R[i] + 1;
            long long tmp2 = query(l, r, 1);
            ans = max(ans, 1LL * (d[i] - d[i + 1]) * (d[i + 1] - d[i]) + pre[i] - tmp1 + suf[i + 1] - tmp2);
        }
        cout << ans << endl;
    }
    return 0;
}