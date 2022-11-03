#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())


const long long MOD = 1e9 + 7;

long long add(long long x, long long y){
    long long ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
long long sub(long long x, long long y){
    long long ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
long long mul(long long x, long long y){
    return (long long)x * y % MOD;
}


const long long mx = 1e6 + 10;

pair<long long, long long> a[mx];
map<long long, long long> sim, ada;
void solve(){
    long long n;
    sim.clear();
    ada.clear();
    cin >> n;
    // n = rand() % 10 + 1;
    for(long long i = 1; i <= n; i++){
        cin >> a[i].f;
        // a[i].f = i - n + (rand() % n);
        sim[a[i].f] = i;
        a[i].s = i;
    }
    sort(a + 1, a + n + 1);
    for(long long i = 1; i <= n; i++){
        if(a[i].f == 0){
            cout << 1 << '\n' << a[i].s << '\n';
            return;
        }
        if(sim.count(-a[i].f)){
            cout << 2 << '\n' << sim[-a[i].f] << ' ' << a[i].s << '\n';
            return;
        }
    }
    vector<pair<long long, long long>> neg, pos;
    for(long long i = 1; i <= n; i++){
        if(a[i].f < 0){
            neg.pb(a[i]);
        }
        else{
            pos.pb(a[i]);
        }
    }
    reverse(ALL(neg));
    
    vector<long long> pneg(sz(neg)), ppos(sz(pos));
    for(long long i = 0; i < sz(neg); i++){
        if(i == 0) pneg[i] = neg[i].f;
        else pneg[i] = pneg[i - 1] + neg[i].f;
        ada[pneg[i]] = i;
    }
    for(long long i = 0; i < sz(pos); i++){
        if(i == 0) ppos[i] = pos[i].f;
        else ppos[i] = ppos[i - 1] + pos[i].f;
        if(ada.count(-ppos[i])){
            vector<long long> ans;
            for(long long j = 0; j <= i; j++) ans.pb(pos[j].s);
            for(long long j = 0; j <= ada[-ppos[i]]; j++) ans.pb(neg[j].s);
            cout << sz(ans) << '\n';
            for(long long x : ans) cout << x << ' ';
            cout << '\n';
            return;
        }
    }
    ada.clear();
    reverse(ALL(neg));
    for(long long i = 0; i < sz(neg); i++){
        if(i == 0) pneg[i] = neg[i].f;
        else pneg[i] = pneg[i - 1] + neg[i].f;
        ada[pneg[i]] = i;
    }
    for(long long i = 0; i < sz(pos); i++){
        if(i == 0) ppos[i] = pos[i].f;
        else ppos[i] = ppos[i - 1] + pos[i].f;
        if(ada.count(-ppos[i])){
            vector<long long> ans;
            for(long long j = 0; j <= i; j++) ans.pb(pos[j].s);
            for(long long j = 0; j <= ada[-ppos[i]]; j++) ans.pb(neg[j].s);
            cout << sz(ans) << '\n';
            for(long long x : ans) cout << x << ' ';
            cout << '\n';
            return;
        }
    }
    ada.clear();
    reverse(ALL(pos));
    for(long long i = 0; i < sz(neg); i++){
        if(i == 0) pneg[i] = neg[i].f;
        else pneg[i] = pneg[i - 1] + neg[i].f;
        ada[pneg[i]] = i;
    }
    for(long long i = 0; i < sz(pos); i++){
        if(i == 0) ppos[i] = pos[i].f;
        else ppos[i] = ppos[i - 1] + pos[i].f;
        if(ada.count(-ppos[i])){
            vector<long long> ans;
            for(long long j = 0; j <= i; j++) ans.pb(pos[j].s);
            for(long long j = 0; j <= ada[-ppos[i]]; j++) ans.pb(neg[j].s);
            cout << sz(ans) << '\n';
            for(long long x : ans) cout << x << ' ';
            cout << '\n';
            return;
        }
    }
    ada.clear();
    reverse(ALL(neg));
    for(long long i = 0; i < sz(neg); i++){
        if(i == 0) pneg[i] = neg[i].f;
        else pneg[i] = pneg[i - 1] + neg[i].f;
        ada[pneg[i]] = i;
    }
    for(long long i = 0; i < sz(pos); i++){
        if(i == 0) ppos[i] = pos[i].f;
        else ppos[i] = ppos[i - 1] + pos[i].f;
        if(ada.count(-ppos[i])){
            vector<long long> ans;
            for(long long j = 0; j <= i; j++) ans.pb(pos[j].s);
            for(long long j = 0; j <= ada[-ppos[i]]; j++) ans.pb(neg[j].s);
            cout << sz(ans) << '\n';
            for(long long x : ans) cout << x << ' ';
            cout << '\n';
            return;
        }
    }

    /////////////////
    vector<long long> ans;
    for(auto &i : neg) i.f = -i.f;
    sort(ALL(neg));
    sort(ALL(pos));
    for(long long cari = 1; 1; cari++){
        long long batas = sz(pos);
        long long sisa = cari;
        ans.clear();
        while(sisa > 0){
            if(batas == 0) break;
            long long in = upper_bound(pos.begin(), pos.begin() + batas, make_pair(sisa, n + 5)) - pos.begin() - 1;
            if(in == -1) break;
            batas = in;
            sisa -= pos[in].f;
            ans.pb(pos[in].s);
        }
        if(sisa > 0) continue;
        sisa = cari;
        batas = sz(neg);
        while(sisa > 0){
            if(batas == 0) break;
            long long in = upper_bound(neg.begin(), neg.begin() + batas, make_pair(sisa, n + 5)) - neg.begin() - 1;
            if(in == -1) break;
            batas = in;
            sisa -= neg[in].f;
            ans.pb(neg[in].s);
        }
        if(sisa > 0) continue;
        cout << sz(ans) << '\n';
        for(long long x : ans) cout << x << ' ';
        cout << '\n';
        return;
    }
    // cout << n << endl;
    // for(long long i = 1; i <= n; i++){
    //     debug(i, a[i].f, a[i].s);
    // }
    
    assert(false);
}   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--) solve();
}