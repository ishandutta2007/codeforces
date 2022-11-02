#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define N_MAX 200005

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

const ll MOD = 998244353;


class ModInt{
    public:
    ll v;
    ModInt(ll _v = 0){
        v = _v;
    }
    ModInt operator+(ll n){
        return ModInt((v+n)%MOD);
    }
    ModInt operator-(ll n){
        return ModInt((v-n+MOD)%MOD);
    }
    ModInt operator*(ll n){
        return ModInt((v*n)%MOD);
    }
    ModInt operator/(ll n){
        return ModInt((ModInt(n).inv()*v).v%MOD);
    }

    void operator+=(ll n){
        v = (v+n)%MOD;
    }
    void operator-=(ll n){
        v = (v-n+MOD)%MOD;
    }
    void operator*=(ll n){
        v = (v*n)%MOD;
    }
    
    
    ModInt operator+(ModInt n){
        return ModInt((v+n.v)%MOD);
    }
    ModInt operator-(ModInt n){
        return ModInt((v-n.v+MOD)%MOD);
    }
    ModInt operator*(ModInt n){
        return ModInt((v*n.v)%MOD);
    }
    ModInt operator/(ModInt n){
        return ModInt((n.inv()*v).v%MOD);
    }

    void operator+=(ModInt n){
        v = (v+n.v)%MOD;
    }
    void operator-=(ModInt n){
        v = (v-n.v+MOD)%MOD;
    }
    void operator*=(ModInt n){
        v = (v*n.v)%MOD;
    }

    void operator=(ModInt n){
        v = n.v;
    }
    void operator=(ll n){
        v = n;
    }

    ModInt inv(){
        if(v == 1) return ModInt(1);
        else return ModInt(MOD-ModInt(MOD%v).inv().v*(MOD/v)%MOD);
    }
};

ostream& operator<<(ostream& os, const ModInt& m){
    os << m.v;
    return os;
}

istream & operator >> (istream &in,  ModInt &m){
    in >> m.v;
    return in;
}


ModInt inv[N_MAX];

void init(){
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=(ModInt)MOD-inv[MOD%i]*(MOD/i);
    }
}

int n, m;
ll d[200000];
ModInt d_sum[200001];

void solve(){
    int a, b;
    cin >> a >> b;
    
    int cnt_smaller = lower_bound(d, d+n, b) - d;
    int cnt_greater = n-cnt_smaller;
    ModInt sum_smaller = d_sum[cnt_smaller];
    ModInt sum_greater = d_sum[n]-sum_smaller;
    if(cnt_greater < a){
        cout << 0 << endl;
        return;
    }
    int m = cnt_greater;
    ModInt ans = 0;
    ans += ModInt(m+1-a)*inv[m+1]*sum_smaller;
    ans += ModInt(m-a)*inv[m]*sum_greater;
    
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> d[i];
    sort(d, d+n);
    for(int i = 1; i <= n; i++) d_sum[i] = d_sum[i-1]+d[i-1];
    for(int i = 0; i < m; i++) solve();
}