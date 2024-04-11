#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int cnt[500005][22];
P p[200000];
int R = 500000;

int calc(int l, int n){
    int cur = l;
    for(int i = 0; i <= 20; i++){
        int m = (1<<i);
        if(n&m) cur = cnt[cur][i];
    }
    return cur;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        p[i] = P(l, r);
    }
    sort(p, p+n);
    int idx = 0;
    int rmax = 0;
    for(int i = 0; i <= R; i++){
        while(idx < n && p[idx].first <= i){
            rmax = max(rmax, p[idx].second);
            idx++;
        }
        cnt[i][0] = max(rmax, i);
    }
    for(int j = 1; j <= 18; j++){
        for(int i = 0; i <= R; i++){
            cnt[i][j] = cnt[cnt[i][j-1]][j-1];
        }
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        int l = 0, r = 200002;
        if(calc(x, r) < y){
            printf("%d\n", -1);
            continue;
        }
        while(r-l>1){
            int c = (l+r)/2;
            if(calc(x, c) < y) l = c;
            else r = c;
        }
        printf("%d\n", r);
    }
}