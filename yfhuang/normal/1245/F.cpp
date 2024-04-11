#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

int d1[55], d2[55];


LL f[55][2][2];

LL cal(int id, int f1, int f2){
    //cout << id << " " << f1 << " " << f2 << endl;
    if(id == -1)
        return 1;
    if(f[id][f1][f2] != -1)
        return f[id][f1][f2];
    LL cur = 0;
    for(int d3 = 0;d3 < 2;d3++){
        for(int d4 = 0;d4 < 2;d4++){
            if(d3 == 1 and d4 == 1)
                continue;
            if(f1 and d3 > d1[id])
                continue;
            if(f2 and d4 > d2[id])
                continue;
            int f3 = f1 & (d3 == d1[id]);
            int f4 = f2 & (d4 == d2[id]); 
            cur += cal(id - 1, f3, f4);
            //cout << cur << endl;
        }
    }
    return f[id][f1][f2] = cur;
}

LL solve(int l, int r){
    if(l < 0)
        return 0;
    if(r < 0)
        return 0;
    for(int i = 0;i < 50;i++){
        d1[i] = l % 2;
        l /= 2;
        d2[i] = r % 2;
        r /= 2;
    }
    memset(f, -1, sizeof(f));
    return cal(49, 1, 1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        LL l, r;
        cin >> l >> r;
        l--;
        LL ans = solve(r, r) - 2 * solve(l, r) + solve(l, l);
        cout << ans << endl;
    }
    return 0;
}