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

const int maxn = 4e5 + 5;
vector<int> d[maxn];
const int N = 2e5 + 1;

void init(){
    for(int i = 1;i < maxn;i++){
        for(int j = i;j < maxn;j += i){
            d[j].push_back(i);
        }
    }
}

struct query{
    int l, r, id;
    query(int _l=0, int _r=0, int _id=0):l(_l), r(_r), id(_id){}
    bool operator < (const query & rhs) const{
        return r < rhs.r;
    }
}q[maxn];

ll ans[maxn];

ll c[maxn];

void add(int pos, ll v){
    for(int i = pos;i < maxn;i += i & -i){
        c[i] += v;
    }
}

ll sum(int pos){
    ll val = 0;
    for(int i = pos;i > 0;i -= i & -i){
        val += c[i];
    }
    return val;
}

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

ll check(int l, int r){
    int cnt = 0;
    for(int i = l;i <= r;i++){
        for(int j = i + 1;j <= r;j++){
            for(int k = j + 1;k <= r;k++){
                ll LCM = lcm(i, j);
                LCM = lcm(LCM, k); 
                if(LCM >= i + j + k){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    cin >> T;
    int l, r;
    for(int i = 1;i <= T;i++){
        cin >> l >> r;
        q[i] = query(l, r, i);
    }
    sort(q + 1, q + 1 + T);
    int j = 1;
    for(int i = 1;i < N;i++){
        int nj = j - 1;
        while(nj < T and q[nj + 1].r <= i){
            nj++;
        } 
        int val = 0;
        if(d[i * 2].size() >= 4){
            int sz = d[i * 2].size();
            for(int k = sz - 4;k >= max(0, sz - 5);k--){
                if(d[i * 2][sz - 2] + d[i * 2][sz - 3] + d[i * 2][k] > 2 * i){
                    add(N - d[i * 2][k], 1);
                }
            }
        }
        for(int k = d[i].size() - 1;k >= 0;k--){
            if(d[i][k] < i){
                val++;
                add(N - d[i][k], val - 1);
            }
        }
        for(int k = j;k <= nj;k++){
            int id = q[k].id;
            int len = q[k].r - q[k].l + 1;
            ans[id] = 1LL * len * (len - 1) * (len - 2) / 6 - sum(N - q[k].l);
        }
        j = nj + 1;
    } 
    for(int i = 1;i <= T;i++){
        cout << ans[i] << endl;
    }
    return 0;
}