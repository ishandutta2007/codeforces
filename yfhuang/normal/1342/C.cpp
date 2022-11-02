#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int pre[205 * 205];

void init(int a, int b){
    memset(pre, 0, sizeof(pre));
    for(int i = 1;i <= a * b;i++){
        if((i % a) % b != (i % b) % a)
           pre[i]++; 
        pre[i] += pre[i - 1];     
    } 
}

ll cal(ll v, int a, int b){
    ll p = (v - 1) / (a  * b);
    ll m = v - p * (a * b);
    return p * pre[a * b] + pre[m];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a, b, q;
        ll l, r;
        cin >> a >> b >> q;
        init(a, b);
        for(int i = 1;i <= q;i++){
            cin >> l >> r;
            cout << cal(r, a, b) - cal(l - 1, a, b);
            if(i == q)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}