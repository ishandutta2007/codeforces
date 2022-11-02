#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 2e5 + 5;
int p[maxn];
int a[maxn];
int last[maxn];
int pos[maxn];
int st[maxn][22];
int Right[maxn];
int vst[maxn][22];
int n, m, q;
void init(){
    for(int i = 1;i <= m;i++){
        vst[i][0] = Right[i];
    }
    for(int j = 1;j < 22;j++){
        for(int i = 1;i + (1 << j) - 1 <= m;i++){
            vst[i][j] = min(vst[i][j - 1], vst[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int k = 31 - __builtin_clz(r - l + 1);
    return min(vst[l][k], vst[r - (1 << k) + 1][k]);
}
int main(){
    while(cin >> n >> m >> q){
        for(int i = 0;i < n;i++){
            scanf("%d", &p[i]);
            pos[p[i]] = i;
        }
        memset(last, 0, sizeof(last));
        memset(st, 0, sizeof(st));
        for(int i = 1;i <= m;i++){
            scanf("%d", &a[i]);
        }
        for(int i = m;i >= 1;i--){
            int position = pos[a[i]];
            int val = p[(position + 1) % n];
            if(last[val] == 0){
                st[i][0] = m + 1;
            }else{
                st[i][0] = last[val];
            }
            last[a[i]] = i;
        }
        for(int i = 0;i < 22;i++){
            st[m + 1][i] = m + 1;
        }
        for(int i = 1;i < 22;i++){
            for(int j = 1;j <= m;j++){
                st[j][i] = st[st[j][i - 1]][i - 1];
            }
        }
        for(int i = 1;i <= m;i++){
            Right[i] = i;
        }
        int N = n - 1;
        for(int i = 0;i < 22;i++){
            if(N & (1 << i)){
                for(int j = 1;j <= m;j++){
                    Right[j] = st[Right[j]][i];
                }
            }
        }
        init();
        for(int i = 1;i <= q;i++){
            int l, r;
            scanf("%d%d", &l, &r);
            int ret = query(l, r); 
            if(ret <= r) putchar('1');
            else putchar('0');
        }
        puts("");
    } 
    return 0;
}