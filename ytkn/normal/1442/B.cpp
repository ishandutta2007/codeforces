#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;
typedef pair<int, bool> P;

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

int n, k;
int a[200000], b[200000];
int idx[200000];

void solve(){
    cin >> n >> k;
    set<int> sta;
    vector<bool> ok(n, true);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        idx[a[i]] = i;
        sta.insert(a[i]);
    }
    bool ng = false;
    for(int i = 0; i < k; i++) {
        cin >> b[i];
        b[i]--;
        if(sta.count(b[i]) == 0){
            ng = true;
        }
        ok[idx[b[i]]] = false;
    }
    if(ng){
        cout << 0 << endl;
        return;
    }
    set<P> st;
    ModInt ans = 1;
    for(int i = 0; i < n; i++){
        st.insert(P(i, ok[i]));
        // cout << i << "," << ok[i] << endl;
    }
    for(int i = 0; i < k; i++){
        P cur = P(idx[b[i]], false);
        // cout << "====" << idx[b[i]] << endl;
        auto ptr = st.find(P(idx[b[i]], false));
        if(ptr == st.begin()){
            ptr++;
            P p = *ptr;
            if(!p.second) {
                cout << 0 << endl;
                return;
            }
            ptr--;
            st.erase(cur);
            st.erase(p);
        }else{
            ptr--;
            P pl = *ptr;
            int c = 0;
            if(pl.second) c++;
            ptr++; ptr++;
            // cout << pl.first << '-' << ptr->first << endl;
            P pr;
            if(ptr != st.end()) pr = *ptr;
            if(pr.second) c++;
            if(c == 0){
                cout << 0 << endl;
                return;
            }
            
            ans *= c;
            if(pl.second){
                st.erase(cur);
                st.erase(pl);
            }else{
                st.erase(cur);
                st.erase(pr);
            }
        }
        st.insert(P(idx[b[i]], true));
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}