#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int t;
int n, m;
const int maxn = 1e5 + 5;

int a[maxn], b[maxn];

int c[maxn];

int sum(int x){
    int ret = 0;
    for(int i = x;i > 0;i -= i & -i){
        ret += c[i];
    }
    return ret;
}

void add(int x, int v){
    for(int i = x;i < maxn;i += i & -i){
        c[i] += v;
    }
}

int pos[maxn];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
            pos[a[i]] = i;
            c[i] = 0;
        }
        long long ans = 0;
        for(int j = 1;j <= m;j++){
            scanf("%d", &b[j]);
            int pre = sum(pos[b[j]]);
            int suf = (j - 1) - pre;
            if(suf > 0){
                ans += 1;
            }else{
                ans += 2 * (pos[b[j]] - 1 - pre) + 1;
            }
            add(pos[b[j]], 1);
        }
        cout << ans << endl;
    }
    return 0;
}