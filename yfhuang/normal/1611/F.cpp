#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;

const int maxn = 2e5 + 5;
ll p[maxn];
ll c[maxn][25];
int n, s;
int a[maxn];

void init(int m){
    for(int j = 1;j <= m;j++){
        c[j][0] = p[j];
    }
    for(int j = 1;(1 << j) <= m;j++){
        for(int i = 1;i + (1 << j) - 1 <= m;i++){
            c[i][j] = min(c[i][j-1], c[i+(1<<(j-1))][j-1]);
        }
    }
}

ll query(int l, int r){
    int k = 31 - __builtin_clz(r - l + 1);
    return min(c[l][k], c[r-(1<<k)+1][k]);
} 

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> s;
        p[0] = 0;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            p[i] = p[i-1] + a[i];
        }
        init(n);
        int ans = 0;
        pi sol = {-1, -1};
        for(int i = 1;i <= n;i++){
            int l = i-1, r = n;
            while(l < r){
                int m = (l + r + 1) / 2;
                if(query(i, m) - p[i-1] >= -s){
                    l = m;
                }else{
                    r = m-1;
                }
            } 
            if(l - i + 1 > ans){
                ans = l - i + 1;
                sol = mp(i, l);
            }
        }
        if(ans == 0){
            cout << -1 << endl;
        }else{
            cout << sol.fi << " " << sol.se << endl;
        }
    }
    return 0;
}