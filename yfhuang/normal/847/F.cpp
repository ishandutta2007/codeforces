#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int n,k,m,a;

const int maxn = 105;
int g[maxn];
struct candidate{
    int n,l;
    int id;
    bool operator < (const candidate & rhs) const{
        return n < rhs.n || (n == rhs.n && l > rhs.l);
    }
}c[maxn];

int pre[maxn];

int r[maxn];

int main(){
    cin >> n >> k >> m >> a;
    for(int i = 1;i <= n;i++){
        c[i].n = 0,c[i].l = 0;
        c[i].id = i;
    }
    for(int i = 1;i <= a;i++){
        scanf("%d",&g[i]);
        c[g[i]].n++;c[g[i]].l = i;
    }
    sort(c + 1,c + 1 + n);
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + c[i].n;
    }
    if(k == n){
        for(int i = 1;i <= n;i++){
            if(c[i].n > 0){
                r[c[i].id] = 1;
            }else{
                if(m - a > 0) r[g[i]] = 2;
                else r[c[i].id] = 3;
            }
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (k <= n - i) continue;
            if(c[i].n == 0) continue;
            int sum = (pre[i - 1] - pre[n - k - 1]);
            if (m - a < (c[i].n + 1) * (k + i - n) - sum) {
                r[c[i].id] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if(c[i].n == 0 && m - a == 0){
                r[c[i].id] = 3;
            }
            candidate tmp = c[i];
            if (m - a > 0) tmp.n += m - a, tmp.l = m;
            if (tmp < c[n - k + 1]) {
                r[c[i].id] = 3;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(r[i] == 0) printf("2");
        else printf("%d",r[i]);
        printf("%c",i == n ? '\n' : ' ');
    }
    return 0;
}